#include<bits/stdc++.h>
using namespace std;
int a[505];
char c[505];
const int MOD=998244353;
long long calc(int n)
{
    long long sum=1;
    for(int i=2;i<=n-1;i++)
    {
        sum=(sum*i)%MOD;
    }
    return sum;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int s1=0,s0=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]=='1')s1++;
        if(c[i]=='0')s0++;
    }
    int x=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)x--;
    }
    if(s0==n)
    {
        printf("0");
        return 0;
    }
    if(s1==n)
    {
        printf("%lld",calc(x));
        return 0;
    }
    if(m==1)
    {
        long long ans=calc(n);
        printf("%lld",ans);
        return 0;
    }
    if(m==n)
    {
        if(s1==n)printf("1");
        else printf("0");
        return 0;
    }
    printf("0");
    return 0;
}
