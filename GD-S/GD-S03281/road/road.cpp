#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pii;
const int N=1e5+10;
const ll INF=LONG_LONG_MAX;
bitset <N>b[N];
ll c[12];
bitset <N>bb;
vector<vector<pii>> graph(N);
int nl;

ll summ=INF;
void dfs(int x,ll sum)
{
	if(b[x]==bb)
	{
		summ=min(summ,sum);
		return;
	}
	for(int i=0;i<(int)graph[x].size();i++)
	{
		pii top=graph[x][i];
		if(b[x][top.first]==1)
		{
			continue;
		}
		bitset <N>l=b[top.first];
		b[x][top.first]=1;
		b[top.first][x]=1;
		
		b[top.first]|=b[x];
		sum+=top.second;
		
		dfs(top.first,sum);
	
		b[top.first]=l;
		
		sum-=top.second;
	}
	return;
}


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

		ll n,m,k;
		
		cin>>n>>m>>k;
		
		for(int i=1;i<=n;i++)
		{
			bb[i]=1;
		}
		
		ll u,v,w;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			graph[u].push_back(make_pair(v,w));
			graph[v].push_back(make_pair(u,w));
		}
		
		for(int i=1+n;i<=k+n;i++)
		{
			b[i][i]=1;
			cin>>c[i];
			int a;
			for(int j=1;j<=n;j++)
			{
				b[j][j]=1;
				cin>>a;
				graph[i].push_back(make_pair(j,a));
				graph[j].push_back(make_pair(i,a));
			}
			
			
		}
		
		dfs(1,0);
		
		cout<<summ<<"\n";
		
	return 0;
}
