#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
long long ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) ans = (1ll * i * ans) % mod;
    printf("%lld\n",ans);
    return 0;
}