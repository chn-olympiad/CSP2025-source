#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n,k,ans;
ll a[500005],maxn;
ll cnt[500005][21]; //cnt[i][k] cong 1 dao i suoyou de shuzhong erjinzhixia di k wei shi 1 de geshu
bool flag,flag2;

int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    flag=flag2=true;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        maxn=max(maxn,a[i]);
        if (a[i]!=1) flag=false;
        if (a[i]>1) flag2=false;
    }
    if (flag){
        if (k==1){
            cout << n << endl;
        }else {
            cout << n/2 << endl;
        }
    }else if (flag2){
        if (k==0){
            for (int i=1;i<=n;i++){
                if (a[i]==1&&a[i+1]==1){
                    ans++;
                    i++;
                }else if (a[i]==0){
                    ans++;
                }
            }
            cout << ans << endl;
        }else {
            for (int i=1;i<=n;i++){
                if (a[i]==1){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }else {
        for (int i=1;i<=n;i++){
            for (int j=0;(1<<j)<=a[i];j++){
                if ((a[i]>>j)&1) cnt[i][j]=cnt[i-1][j]+1;
            }
        }
        for (int len=1;len<=n;len++){
            ll res=0;
            for (int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                bool f=true;
                for (int p=0;(1<<p)<=k;p++){
                    if ((k>>p)&1){
                        if ((cnt[j][p]-cnt[i-1][p])%2!=0){
                            flag=false;
                            break;
                        }
                    }else {
                        if ((cnt[j][p]-cnt[i-1][p]%2==0)){
                            flag=false;
                            break;
                        }
                    }
                }
                if (f){
                    res++;
                    i=j+1;
                }
            }
            ans=max(ans,res);
        }
        cout << ans << endl;
    }
    return 0;
}
//upd:10:25 finish teshuxingzhi A&B
//upd:11:39 zhengjiegenbenxiangbuchulai baoliyebuhui T2T3de nanduxiangchazhemeda?
//rp++