#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=21,maxm=270000,mod=998244353;
int n,m,a[maxn],b[maxn],ppc[maxm],dp[maxn][maxm],ans;
char c;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c,a[i]=c-48;
    for(int i=1;i<=n;i++)cin>>b[i];
    if(m==n){
        for(int i=1;i<=n;i++)if(a[i]==0||b[i]==0){
            cout<<"0";return 0;
        }
        ans=1;for(int i=1;i<=n;i++)ans=(long long)ans*i%mod;
        cout<<ans;return 0;
    }
    dp[0][0]=1;for(int i=0;i<(1<<n);i++)ppc[i]=__builtin_popcount(i);
    for(int i=1;i<=n;i++)
        for(int k=0;k<(1<<n);k++)if(ppc[k]==i-1){
            for(int l=1;l<=n;l++)if(!(k&1<<l-1))for(int j=0;j<i;j++)
                dp[j+bool(a[i]&&b[l]>=i-j)][k|1<<l-1]=(dp[j+bool(a[i]&&b[l]>=i-j)][k|1<<l-1]+dp[j][k])%mod;
        }
    for(int i=m;i<=n;i++)ans=(ans+dp[i][(1<<n)-1])%mod;
    cout<<ans;
    //cout<<"\n";
    //for(int i=0;i<=10;i++)cout<<dp[i][(1<<n)-1]<<" ";
    //cout<<dp[2][1022];
    return 0;
}