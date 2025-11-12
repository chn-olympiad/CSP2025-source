#include<bits/stdc++.h>
#define int long long 
#define mod 998244353
#define N 505
using namespace std;
int n,m,a[N],b[N],c[N],f[N][N],tong[N];
char ch[N];
int ksm(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret*=x,ret%=mod;
        x*=x,x%=mod,y>>=1;
    }
    return ret;
}
void work1()
{
    for(int i=1;i<=n;i++)
        tong[c[i]]++;
    for(int i=1;i<=n;i++)
        tong[i]+=tong[i-1];
    int cnt=0,ans=1;
    for(int i=1;i<=n;i++)
        if(a[i])
            (ans*=tong[i-1]-cnt)%=mod,cnt++;
    for(int i=1;i<=n-cnt;i++)
        (ans*=i)%=mod;
    int ans2=1;
    for(int i=1;i<=n;i++)
        (ans2*=i)%=mod;
    printf("%lld\n",(ans2-ans+mod)%mod);
    exit(0);
}
void work2()
{
    for(int i=1;i<=n;i++)
        b[i]=i;
    int ans=0;
    do
    {
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(s>=c[b[i]]) s++;
            else if(a[i]==0) s++;
        }
        if(s<=n-m) ans++;
            
    }while(next_permutation(b+1,b+1+n));
    printf("%lld\n",ans);
    exit(0);
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",ch+1);
    for(int i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)
        a[i]=ch[i]-'0';
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    if(sum<m)
    {
        puts("0");
        return 0;
    }
    if(m==1)
        work1();
    if(n<=10)
        work2();
    return 0;
}