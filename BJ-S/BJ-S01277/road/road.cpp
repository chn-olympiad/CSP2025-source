#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e4+5;

int n,m,k;
ll g[N][N],pri[N],dis[N],ans;
bool flag[N];
inline void read(int &x)
{
    x=0;
    int fh=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') fh=-1;
    for(;isdigit(ch);ch=getchar())
        x=x*10+ch-'0';
}
inline void read_ll(ll &x)
{
    x=0;
    int fh=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') fh=-1;
    for(;isdigit(ch);ch=getchar())
        x=x*10+ch-'0';
}
inline void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) g[i][j]=0;
            else g[i][j]=1e18;
    while(m--)
    {
        int u,v;
        ll w;
        read(u),read(v),read_ll(w);
        g[u][v]=min(g[u][v],w);
        g[v][u]=g[u][v];
    }
    while(k--)
    {
        ll c;
        read_ll(c);
        for(int j=1;j<=n;j++)
            read_ll(pri[j]);
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],pri[i]+pri[j]+c);
                g[j][i]=g[i][j];
            }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
        dis[i]=g[1][i];
    flag[1]=1;
    for(int i=1;i<n;i++)
    {
        int pos=0;
        ll mini=LLONG_MAX;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&mini>dis[j])
                pos=j,mini=dis[j];
        flag[pos]=1;
        for(int j=1;j<=n;j++)
            if(!flag[j])
                dis[j]=min(dis[j],g[pos][j]);
    }
    for(int i=1;i<=n;i++)
        ans+=dis[i];
    write(ans);
    return 0;
}