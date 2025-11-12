#include<bits/stdc++.h>
using namespace std;
const int N=500;
const long long mod=998244353;
int n,m,a[N+5],c[N+5];
long long f[1<<18][20];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m; char op;
    for(int i=1;i<=n;i++) cin>>op,a[i]=op-'0';
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n>18){cout<<0; return 0;}
    f[0][0]=1;
    for(int S=0;S<(1<<n)-1;S++){
        int bit=__builtin_popcount(S);
        for(int k=0;k<=bit;k++){
            for(int i=1;i<=n;i++){
                if((S>>(i-1))&1) continue;
                int T=S+(1<<(i-1)),delta=(a[bit+1]==0||k>=c[i]);
                f[T][k+delta]=(f[T][k+delta]+f[S][k])%mod;
            }
        }
    }
    long long ans=0;
    for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
    cout<<ans;
    return 0;
}