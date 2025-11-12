#include<bits/stdc++.h>
#define mm 510
#define int long long
#define mod 998244353
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int n,m;
string s;
int c[mm];
int a[mm],vis[mm];
int ans;
void check()
{
    int add=0,del=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
        {
            del++;
            continue;
        }
        if(del>=c[a[i]]) del++;
        else add++;
    }
    if(add>=m) ans++;
}
void dfs(int x)
{
    if(x==n+1)
    {
        check();
        return ;
    }
    for(int i=1;i<=n;i++)if(!vis[i])
    {
        vis[i]=true;
        a[x]=i;
        dfs(x+1);
        vis[i]=false;
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s;s=' '+s;
    for(int i=1;i<=n;i++) c[i]=read();
    if(n<=10)
    {
        dfs(1);
        printf("%lld\n",ans);
        return 0;
    }
    int add=0;
    for(int i=1;i<=n;i++) add+=s[i]-'0';
    int flag=false;
    for(int i=1;i<=n;i++)if(c[i]==0) flag=true;
    if(add<m){puts("0");exit(0);}
    if((add==n || m==n) && !flag)
    {
        ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        printf("%lld\n",ans);
    }
    puts("0");
}