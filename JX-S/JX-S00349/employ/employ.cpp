#include<bits/stdc++.h>
// #define DEBUG
#ifdef DEBUG
#define perr(...) fprintf(stderr,__VA_ARGS__)
#else
#define perr(...) void(0)
#endif
using namespace std;
const int mn=505,mod=998244353;
int n,m;
char a[mn];
int s[mn];
int act[mn];
int f[mn][mn][mn];
int jc[mn],inv[mn];
int fpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=1LL*x*res%mod;
        x=1LL*x*x%mod;
        y>>=1;
    }
    return res;
}
void init()
{
    int cap=500;
    jc[0]=1;
    for(int i=1;i<=cap;i++)jc[i]=1LL*jc[i-1]*i%mod;
    inv[cap]=fpow(jc[cap],mod-2);
    for(int i=cap;i>=1;i--)inv[i-1]=1LL*inv[i]*i%mod;
}
int C(int x,int y)
{
    if(x<y || y<0)return 0; 
    return 1LL*jc[x]*inv[y]%mod*inv[x-y]%mod;
}
namespace sol1214
{
    void I()
    {
        int ans=1,tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp+=s[i];
            if(a[i+1]!='0')
            {
                ans=1LL*ans*tmp%mod;
                --tmp;
            }
        }
        ans=1LL*ans*jc[tmp]%mod;
        printf("%d\n",(jc[n]-ans+mod)%mod);
    }
}
namespace sol15
{
    void I()
    {
        if(s[0])printf("0\n");
        else printf("%d\n",jc[n]);
    }
}
namespace sol1
{
    int ans=0;
    int now[mn];
    int st[mn],tp;
    void dfs(int x)
    {
        if(x==n+1)
        {
            int nop=0;
            for(int i=1;i<=n;i++)
            {
                if(nop>=act[now[i]] || a[i]=='0')++nop;
            }
            // perr("%d\n",nop);
            if(n-nop>=m)++ans;
            return;
        }
        for(int i=1;i<=tp;i++)
        {
            if(i!=tp)swap(st[i],st[tp]);
            now[x]=st[tp];
            --tp;
            dfs(x+1);
            ++tp;
            if(i!=tp)swap(st[i],st[tp]);
        }
    }
    void I()
    {
        for(int i=1;i<=n;i++)st[i]=i;
        tp=n;
        dfs(1);
        printf("%d\n",ans);
    }
}
namespace zhyw
{
    int f[262144][20];// chosen , failed
    void I()
    {
        f[0][0]=1;
        for(int i=0;i<(1<<n);i++)
        {
            int num=1;
            for(int j=1;j<=n;j++)
            {
                if(i&(1<<(j-1)))++num;
            }
            for(int j=1;j<=n;j++)
            {
                if(i&(1<<(j-1)))continue;
                for(int k=0;k<=n;k++)
                {
                    if(k>=act[j] || a[num]=='0')
                    {
                        f[i|(1<<(j-1))][k+1]=(f[i|(1<<(j-1))][k+1]+f[i][k])%mod;
                    }
                    else
                    {
                        f[i|(1<<(j-1))][k]=(f[i|(1<<(j-1))][k]+f[i][k])%mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++)
        {
            ans=(ans+f[(1<<n)-1][n-i])%mod;
        }
        printf("%d\n",ans);
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%s",a+1);
    init();
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        act[i]=x;
        ++s[x];
    }
    if(m==1)return sol1214::I(),0;
    if(m==n)return sol15::I(),0;
    if(n<=10)return sol1::I(),0;
    return zhyw::I(),0;
    // f[0][0][s[0]]=1;
    // for(int i=0;i<n;i++)//at day i+1
    // {
    //     for(int j=0;j<=i;j++)//how many are rejected
    //     {
    //         for(int k=0;k<=n;k++)//and how many are frustrated
    //         {
    //             if(a[i+1]=='0')
    //             {

    //                 f[i+1][j+1][k+s[j+1]]=(f[i+1][j+1][k+s[j+1]]+f[i][j][k])%mod;
    //             }
    //             else
    //             {
    //                 f[i+1][j+1][k-1+s[j+1]]=(f[i+1][j+1][k+s[j+1]]+f[i][j][k])%mod;
    //             }
    //         }
    //     }
    // }
}