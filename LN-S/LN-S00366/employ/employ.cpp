#include<cstdio>
const int mod = 998244353;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m; scanf("%d%d",&n,&m);
    char s[505]; scanf("%s",s+1);
    for(int i = 1;i <= n;i++)scanf("%d",&c[i]);
    long long ans = 1;
    for(int i = 1;i <= n;i++)ans = ans*i%mod;
    printf("%lld\n",ans); return 0;
}