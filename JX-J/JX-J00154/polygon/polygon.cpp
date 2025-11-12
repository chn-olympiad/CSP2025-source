#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5010];
long long ans;
const long long mod=998244353;
inline int read()
{
    char ch=getchar();int x=0;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(a[i]==1) cnt1++;
    }
    if(cnt1==n)
    {
        printf("%lld",((1+n-2)*(n-2)/2)%mod);
        return 0;
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) printf("1");
    }
    else if(n==4)
    {
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) ans++;
        if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) ans++;
        if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2) ans++;
        if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2) ans++;
        printf("%lld",ans);
    }
    else if(n==5)
    {
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) ans++;
        if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) ans++;
        if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2) ans++;
        if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2) ans++;
        if(a[1]+a[3]+a[5]>max(a[1],max(a[3],a[5]))*2) ans++;
        if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2) ans++;
        if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2) ans++;
        if(a[2]+a[3]+a[5]>max(a[2],max(a[3],a[5]))*2) ans++;
        if(a[2]+a[4]+a[5]>max(a[2],max(a[4],a[5]))*2) ans++;
        if(a[3]+a[4]+a[5]>max(a[3],max(a[4],a[5]))*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]>max(a[1],max(a[2],max(a[3],a[5])))*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]>max(a[1],max(a[2],max(a[4],a[5])))*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]>max(a[1],max(a[3],max(a[4],a[5])))*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]>max(a[2],max(a[3],max(a[4],a[5])))*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))*2) ans++;
        printf("%lld",ans);
    }
    else if(n==6)
    {
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) ans++;
        if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) ans++;
        if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2) ans++;
        if(a[1]+a[2]+a[6]>max(a[1],max(a[2],a[6]))*2) ans++;
        if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2) ans++;
        if(a[1]+a[3]+a[5]>max(a[1],max(a[3],a[5]))*2) ans++;
        if(a[1]+a[3]+a[6]>max(a[1],max(a[3],a[6]))*2) ans++;
        if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2) ans++;
        if(a[1]+a[4]+a[6]>max(a[1],max(a[4],a[6]))*2) ans++;
        if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2) ans++;
        if(a[2]+a[3]+a[5]>max(a[2],max(a[3],a[5]))*2) ans++;
        if(a[2]+a[3]+a[6]>max(a[2],max(a[3],a[6]))*2) ans++;
        if(a[2]+a[4]+a[5]>max(a[2],max(a[4],a[5]))*2) ans++;
        if(a[2]+a[4]+a[6]>max(a[2],max(a[4],a[6]))*2) ans++;
        if(a[3]+a[4]+a[5]>max(a[3],max(a[4],a[5]))*2) ans++;
        if(a[3]+a[4]+a[6]>max(a[3],max(a[4],a[6]))*2) ans++;
        if(a[4]+a[5]+a[6]>max(a[4],max(a[5],a[6]))*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>max(a[1],max(a[2],max(a[3],a[4])))*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]>max(a[1],max(a[2],max(a[3],a[5])))*2) ans++;
        if(a[1]+a[2]+a[3]+a[6]>max(a[1],max(a[2],max(a[3],a[6])))*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]>max(a[1],max(a[2],max(a[4],a[5])))*2) ans++;
        if(a[1]+a[2]+a[4]+a[6]>max(a[1],max(a[2],max(a[4],a[6])))*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]>max(a[1],max(a[3],max(a[4],a[5])))*2) ans++;
        if(a[1]+a[3]+a[4]+a[6]>max(a[1],max(a[3],max(a[4],a[6])))*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]>max(a[2],max(a[3],max(a[4],a[5])))*2) ans++;
        if(a[2]+a[3]+a[4]+a[6]>max(a[2],max(a[3],max(a[4],a[6])))*2) ans++;
        if(a[2]+a[3]+a[5]+a[6]>max(a[2],max(a[3],max(a[5],a[6])))*2) ans++;
        if(a[2]+a[4]+a[5]+a[6]>max(a[2],max(a[4],max(a[5],a[6])))*2) ans++;
        if(a[3]+a[4]+a[5]+a[6]>max(a[3],max(a[4],max(a[5],a[6])))*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))))*2) ans++;
        printf("%lld",ans);
    }
    return 0;
}