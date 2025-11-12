#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
inline int read()
{
    char ch=getchar();
    int w=0,c=1;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')c=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        w=(w<<1)+(w<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 111111
int rnk[maxn];
int a[maxn][10];
int pos[maxn];
int cnt[4];
struct node{int mx,mid;}st[maxn];
int m=0;
bool vis[maxn];
void solve()
{
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    int n=read(),m=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)a[i][j]=read();
    for(int i=1;i<=n;i++)
    {
        int maxx=0;
        for(int j=1;j<=3;j++)
            if(a[i][j]>maxx)maxx=a[i][j],pos[i]=j;
    }
    for(int i=1;i<=n;i++)cnt[pos[i]]++;
    bool flag=1;
    for(int i=1;i<=3;i++)
        if(cnt[i]>n/2)flag=0;
    if(flag)
    {
        int ans=0;
        for(int i=1;i<=n;i++)ans+=a[i][pos[i]];
        printf("%lld\n",ans);
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(cnt[pos[i]]<=n/2)ans+=a[i][pos[i]];
        else
        {
            int maxx=0,minn=inf,res=0;
            for(int j=1;j<=3;j++)
            {
                maxx=max(maxx,a[i][j]);
                minn=min(minn,a[i][j]);
                res+=a[i][j];
            }
            st[++m]={maxx,res-maxx-minn};
        }
    //for(int i=1;i<=m;i++)cout<<st[i].mx<<" ";
    //puts("");
    int res=0;
    for(int i=1;i<=m;i++)
    {
        if(res<n/2)vis[i]=1,res++;
        else
        {
            int add=0,minid=i;
            for(int j=1;j<=m;j++)
            {
                if(!vis[j])continue;
                int d=st[i].mx+st[j].mid-st[j].mx-st[i].mid;
                if(d>add)add=d,minid=j;
            }
            vis[i]=1;
            vis[minid]=0;
        }
    }
    for(int i=1;i<=m;i++)
        if(vis[i])ans+=st[i].mx;
        else ans+=st[i].mid;
    //for(int i=1;i<=m;i++)cout<<vis[i]<<" ";
    //puts("");
    printf("%lld\n",ans);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}
/*
2020    14533   [18961]
2423    [15344] 16322
1910    6224    [16178]
2038    9963    [19722]
8375    [10557] 5444
3518    14615   [17976]
6188    [13424] 16615
[8769]  509     4394
958     3195    [9953]
[16441] 5313    10926

2020 14533 [18961]
2423 15344 [16322]
1910 6224 [16178]
2038 9963 [19722]
8375 [10557] 5444
3518 14615 [17976]
6188 13424 [16615]
[8769] 509 4394
958 3195 [9953]
[16441] 5313 10926
*/
