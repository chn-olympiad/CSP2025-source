#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5e2+10;
int a[N];
int tong[N];
int cnt[N];
long long dp[N][N];//yi j wei max de i bianxing sum
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int k=0;
    cin>>n;
    int maxa=0,mina=50000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tong[a[i]]++;
        maxa=max(a[i],maxa);
        mina=min(mina,a[i]);
    }
    for(int i=1;i<=n;i++){
        if(tong[i]){
            k++;
        }
        cnt[i]=cnt[i-1]+bool(tong);
    }
    if(tong[1]==n){
        cout<<n-2<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    //xian zhao sanjiaox
    for(int i=maxa;i>=mina;i--){
        //i wei zuichangbian d shuhi
        if(--tong[i]>=0){
            for(int j=mina;j<=i;j++){
                //j wei zuiduanbian d shuzhi
                if(--tong[j]>=0){
                    for(int k=max(i-j+1,j);k<=i;k++){
                        if(tong[k]){
                            dp[3][i]++;
                        }
                    }
                }
                tong[j]++;
            }
        }
        tong[i]++;
        dp[3][i]%=mod;
    }
    for(int i=4;i<=n;i++){
        for(int j=maxa;j>=mina;j--){
            dp[i][j]=dp[i-1][j]*(n-i+1)%mod;
        }
    }
    long long sum=0,sum3=0;
    for(int i=3;i<=n;i++){
        for(int j=mina;j<=maxa;j++){
            sum=sum+dp[i][j];
            sum=sum%mod;
            if(i==3){
                sum3=sum3+dp[i][j];
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
