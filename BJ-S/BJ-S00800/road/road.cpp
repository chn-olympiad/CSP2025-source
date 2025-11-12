#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=2e4+10,M=2e6+10;
struct EDGE
{
    int u,v,w;
}e[M],e1[N],e2[N*20];
vector<int>E[20];
int f[N];
int n,m,k,tp,ans=0,len;
bool cmp(EDGE x,EDGE y)
{
    return x.w<y.w;
}
int find(int x)
{
    return (f[x]==x?x:f[x]=find(f[x]));
}
int solve(int x)
{
    // cout<<">"<<x<<endl;
    int res=0;
    len=0;
    for(int j=1;j<=n+k;j++)f[j]=j;
    for(int i=1;i<=tp;i++)e2[++len]=e1[i];
    for(int i=1;i<=k;i++)
    {
        if(x&(1<<i-1))
        {
            res+=E[i][0];
            for(int j=1;j<=n;j++)
            {
                e2[++len]=(EDGE){i+n,j,E[i][j]};
            }
        }
    }
    sort(e2+1,e2+len+1,cmp);
    for(int i=1;i<=len;i++)
    {
        int u=e2[i].u,v=e2[i].v,w=e2[i].w;
        if(find(u)!=find(v))
        {
            // cout<<u<<' '<<v<<' '<<w<<endl;
            f[find(u)]=find(v);
            res+=w;
        }
    }
    return res;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        E[i].push_back(x);
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            E[i].push_back(x);
        }
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v))
        {
            f[find(u)]=find(v);
            ans+=w;
            e1[++tp]=e[i];
        }
    }
    for(int i=1;i<(1<<k);i++)
    {
        ans=min(ans,solve(i));
    }
    cout<<ans;
    return 0;
}