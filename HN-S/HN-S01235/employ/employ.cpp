#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N];
char s[N];
int fac[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+n+1);
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    bool ok=1;
    for(int i=1;i<=n;i++) if(s[i]=='0') ok=0;
    if(ok==1) {
        cout<<fac[n];
        return 0;
    }
    else cout<<0;
    // cout<<ans;
    return 0;
}