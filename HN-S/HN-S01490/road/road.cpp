#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
int n,m,k,FA[N],ans=LLONG_MAX,s;
struct edge{
    int x,y,w;
}a[11][N];
vector<edge>us,uss;
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(FA[x]!=x)
    FA[x]=find(FA[x]);
    return FA[x];
}
void solve()
{
    sort(us.begin(),us.end(),cmp);
    for(int i=1;i<=n+k;i++)
    {
        FA[i]=i;
    }
    vector<edge>vec;
    for(int i=0;i<us.size();i++)
    {
        int nx=find(us[i].x),ny=find(us[i].y);
        if(nx==ny)
        continue;
        vec.push_back(us[i]);
        FA[nx]=ny;
    }
    swap(us,vec);
    vec.resize(0);
    return;
}
void culc()
{
    for(int i=0;i<us.size();i++)
    {
        s+=us[i].w;
    }
    ans=min(ans,s);
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        uss.push_back(edge{u,v,w});
    }
    us=uss;
    solve();
    uss=us;
    us.clear();
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>a[i][j].w;
            a[i][j].x=n+i;
            a[i][j].y=j;
        }
    }
    for(int i=0;i<(1<<k);i++)
    {
        s=0;
        us=uss;
        for(int j=1;j<=k;j++)
        {
            if((i&(1<<j-1))!=0)
            {
                s+=a[j][0].w;
                for(int l=1;l<=n;l++)
                {
                    us.push_back(a[j][l]);
                }
            }
        }
        solve();
        culc();
    }
    cout<<ans<<'\n';
    return 0;
}