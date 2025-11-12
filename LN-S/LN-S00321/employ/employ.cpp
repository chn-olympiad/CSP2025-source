#include<cstdio>
#define mod 998244353
#define ll long long
#define M 505
char s[M];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    int fl=0;
    for(int i=1;i<=n;i++)
    {
        if(s[1]!='0')fl=1;
    }if(!fl)
    {
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
        }printf("%lld",ans);
        return 0;
    }
    return 0;
}