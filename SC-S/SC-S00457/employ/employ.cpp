#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long f[1048600][20],ans;
int n,m,c[510],t[510],b[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch;cin>>ch;
        t[i]=ch-'0';
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    f[0][0]=1;
    for(int s=0;s<(1<<n);s++)
        for(int i=0;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(!((s>>(j-1))&1)){
                    (f[s|(1<<(j-1))][i+((i>=c[j]||t[__builtin_popcount(s)+1]==0)?1:0)]+=f[s][i])%=mod;
                }
        }
    for(int i=0;i<=n-m;i++)(ans+=f[(1<<n)-1][i])%=mod;
    cout<<ans<<'\n';
    return 0;
}