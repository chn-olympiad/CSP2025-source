#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001],ln,ans=1e18;
bool vis[10011],av_[11];
vector <pair <int,int> > e[10011];
priority_queue <pair<int,pair<int,int> > > eufc;
//greater/less
void bt_ ()
{
    memset(vis,false,sizeof(vis));
    int nans=0,nl=n-1,nol=0;
    for (int i=1;i<=k;i++)
    {
        if (av_[k])
        {
            nans+=c[k];
            nl++;
        }
    }
    vis[1]=true;
    for (auto i:e[1])
    {
        eufc.push({i.second,{1,i.first}});
    }
    while (nol<nl)
    {
        int tw=(eufc.top()).first,tu=((eufc.top()).second).first,tv=((eufc.top()).second).second;
        eufc.pop();
        if (vis[tv])
        {
            continue;
        }
        vis[tv]=true;
        nol++;
        nans+=tw;
    }
    ans=min(ans,nans);
}
void dfs_ (int step_)
{
    //cout << step_ << " ";
    if (step_==k+1)
    {
        bt_();
        return;
    }
    dfs_(step_+1);
    av_[step_]=true;
    dfs_(step_+1);
    av_[step_]=false;
}
signed main ()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        e[u[i]].push_back({v[i],w[i]});
        e[v[i]].push_back({u[i],w[i]});
    }
    //cout << "a\n";
    for (int i=1;i<=k;i++)
    {
        //cout << i << " ";
        cin >> c[i];
        for (int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            e[j].push_back({n+i,a[i][j]});
            e[n+i].push_back({j,a[i][j]});
        }
    }
    //cout << "b\n";
    dfs_(1);
    //cout << "a";
    cout << ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/