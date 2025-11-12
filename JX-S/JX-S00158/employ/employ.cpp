#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,s[N],c[N],jc[N],inv[N],a[N],ans;
bool v[N];
int read()
{
    int sum=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
void check()
{
    int cnt=0,num=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==0||cnt>=c[a[i]]) cnt++;
        else num++;
    }
    ans+=(num>=m);
}
void dfs(int x)
{
    if(x==n+1)
    {
        check();
        return;
    }
    for(int i=1;i<=n;i++)
        if(!v[i])
        {
            v[i]=1;
            a[x]=i;
            dfs(x+1);
            v[i]=0;
        }
}
int qpow(int x,int n)
{
    int sum=1;
    while(n)
    {
        if(n&1) sum=sum*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return sum;
}
void pre()
{
    jc[0]=1;
    for(int i=1;i<=n;i++)
        jc[i]=jc[i-1]*i%mod;
    inv[n]=qpow(jc[n],mod-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}
int A(int n,int m)
{
    if(m>n) return 0;
    return jc[n]*inv[m]%mod;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    bool f1=1;
    int num=0;
    n=read();m=read();
    string ll;
    cin>>ll;
    for(int i=0;i<n;i++)
    {
        s[i+1]=ll[i]-'0';
        if(s[i+1]==0) f1=0;
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=read();
        if(c[i]!=0) num++;
    }
    if(n<=11)
    {
        dfs(1);
        cout<<ans<<endl;
        return 0;
    }
    pre();
    if(num>=m)
        printf("%lld\n",jc[n]);
    else
        putchar('0');
    return 0;
}
