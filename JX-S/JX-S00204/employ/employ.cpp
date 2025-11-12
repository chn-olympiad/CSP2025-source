#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,mod=998244353;
ll n,m,c[N],fac[N];
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s+1;
    fac[0]=1;
    for(int i=1; i<=n; i++) scanf("%lld",c[i]);
    for(ll i=1; i<=n; i++) fac[i]=i*fac[i-1]%mod;
    cout<<fac[n];

    return 0;
}
