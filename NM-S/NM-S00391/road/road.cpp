#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,fa[N],c[15],a[15][N],cnt,ans;
bool vis[15];
vector<pair<pair<int,int>,pair<int,int> > > vec;
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vec.push_back(make_pair(make_pair(w,0),make_pair(u,v)));
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
	}
	for(int i=1;i<=k;i++)
	{
        for(int u=1;u<=n;u++)
        {
            for(int v=1;v<=n;v++)
            {
                if(u==v)
                {
                    continue;
                }
                vec.push_back(make_pair(make_pair(a[i][u]+a[i][v]+c[i],i),make_pair(u,v)));
            }
        }
	}
	sort(vec.begin(),vec.end());
	for(auto x:vec)
    {
        int u=x.second.first,v=x.second.second;
        if(cnt==n-1)
        {
            break;
        }
        if(find(u)==find(v))
        {
            continue;
        }
        fa[find(u)]=find(v);
        cnt++;
        ans+=x.first.first;
        if(!vis[x.first.second])
        {
            vis[x.first.second]=1;
        }
        else
        {
            ans-=c[x.first.second];
        }
    }
    cout<<ans;
	return 0;
}
