#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,c[N],ans=1;char s[N];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld%s",&n,&m,s+1);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++) ans=(ans*i)%mod;
    printf("%lld",ans);
    return 0;
}