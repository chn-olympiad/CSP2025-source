#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=5005,mod=998244353;
int n,a[N],m,ans,dp[N][N];
void add(int &x,int y)
{
    x=(x+y)%mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    m=a[n]+1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0,x;j<=m;j++)
        {
            if(!dp[i-1][j])
                continue;
            add(dp[i][j],dp[i-1][j]);
            x=j+a[i];
            if(x>m)
                x=m;
            add(dp[i][x],dp[i-1][j]);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=m-1;j;j--)
            add(dp[i][j],dp[i][j+1]);
    for(int i=3;i<=n;i++)
    {
        add(ans,dp[i-1][a[i]+1]);
      //  cout<<ans<<endl;
    }
    write(ans);
    return 0;
}
