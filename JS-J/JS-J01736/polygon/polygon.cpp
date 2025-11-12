#include<iostream>
#include<algorithm>
using namespace std;
const int modn=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,a[5001],sum[5001]={0},n1[5001][5001]={{1}},dp[5001][5001]={{1}},cnt[5001]={1};
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i],cnt[i]=(cnt[i-1]<<1)%modn;
        for(int j=0;j<=500;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%modn;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=cnt[i-1];
        for(int j=0;j<=a[i];j++){
            res=(res-dp[i-1][j]+modn)%modn;
        }
        ans=(ans+res)%modn;
    }
    cout<<ans;
    return 0;
}
/*
##### ##### #   # #   #  ###  #####     #   # ##### ##### ####   ###      #      ###  #   # #####      ###
  #   #      # #  #   # #   #   #       ## ## #       #   #   # #   #     #       #   ##  # #         #   #
  #   #####   #    # #  #####   #       # # # #####   #   ####  #   #     #       #   # # # #####       ##
  #   #       #    # #  #   #   #       #   # #       #   # #   #   #     #       #   #  ## #          #
  #   #####   #     #   #   #   #       #   # #####   #   #  ##  ###      #####  ###  #   # #####     #####
                                              Line 3 / Line 5                   Canglan Line
Stormterror's Lair              Dawn Winery          |        Dragonspine Camp       |           Cape Oath
     o---------------o---------------o---------------o---------------o---------------o---------------o
                 Wolvendom           |          Springvale                      Dadaupa Gorge
                                  Line 1
*/
