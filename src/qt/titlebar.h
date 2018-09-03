#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QSize>
#include <QTabBar>
#include <QIcon>
#include <qt/walletmodel.h>

namespace Ui {
class TitleBar;
}
class WalletModel;
class TabBarInfo;
class PlatformStyle;

/**
 * @brief The TitleBar class Title bar widget
 */
class TitleBar : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief TitleBar Constructor
     * @param parent Parent widget
     */
    explicit TitleBar(const PlatformStyle *platformStyle, QWidget *parent = 0);
    
    /**
     * @brief TitleBar Destrustor
     */
    ~TitleBar();

    /**
     * @brief setModel Set wallet model
     * @param _model Wallet model
     */
    void setModel(WalletModel *_model);

    /**
     * @brief setTabBarInfo Set the tab bar info
     * @param info Information about tabs
     */
    void setTabBarInfo(QObject* info);

Q_SIGNALS:

public Q_SLOTS:
    /**
     * @brief setBalance Slot for changing the balance
     */
    void setBalance(const interfaces::WalletBalances& balances);

    /**
     * @brief on_navigationResized Slot for changing the size of the navigation bar
     * @param _size Size of the navigation bar
     */
    void on_navigationResized(const QSize& _size);

private:
    Ui::TitleBar *ui;
    WalletModel *model;
    TabBarInfo* m_tab;
    QIcon m_iconCloseTab;
};

#endif // TITLEBAR_H
