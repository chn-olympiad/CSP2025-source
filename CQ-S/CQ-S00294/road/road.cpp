#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
int n,m,k,c[15];
struct node{
	int u,v,w;
	inline friend bool operator < (node x,node y)
	{
		return x.w<y.w; 
	}
};
vector<node> vec[1<<10],e[15];
int f[N<<1];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x] = find(f[x]);
}
inline int work(int z)
{
	for(int i = 1;i<=n+k;i++) f[i] = i;
	int res = 0;
	vector<node> tmp;
	for(auto _:vec[z])
	{
		int u = _.u,v = _.v,w = _.w;
		u = find(u),v = find(v);
		if(u==v) continue;
		f[u] = v,res+=w,tmp.push_back(_);
	}
	vec[z].swap(tmp);
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,vec[0].push_back((node){u,v,w});
	sort(vec[0].begin(),vec[0].end());
	for(int i = 1;i<=k;i++)
	{
		cin>>c[i];
		for(int j = 1,x;j<=n;j++)
			cin>>x,e[i].push_back({i+n,j,x});
		sort(e[i].begin(),e[i].end());
	}
	int ans = 2e18;
	for(int z = 0;z<(1<<k);z++)
	{
		for(int i = 1;i<=k;i++)
		{
			if((z>>i-1)&1)
			{
				int p1 = 0,p2 = 0,z2 = z^(1<<i-1);
				while(p1<vec[z2].size()&&p2<e[i].size())
				{
					if(vec[z2][p1]<e[i][p2]) vec[z].push_back(vec[z2][p1++]);
					else vec[z].push_back(e[i][p2++]);
				}
				while(p1<vec[z2].size()) vec[z].push_back(vec[z2][p1++]);
				while(p2<e[i].size()) vec[z].push_back(e[i][p2++]);
				break;
			}
		}
		int tmp = work(z);
		for(int i = 1;i<=k;i++)
			if((z>>i-1)&1) tmp+=c[i];
		ans = min(ans,tmp);
//		cout<<z<<":\n";
//		for(auto _:vec[z]) cout<<_.u<<' '<<_.v<<' '<<_.w<<'\n';
//		cout<<"now"<<tmp<<'\n';
	}
	cout<<ans;
	return 0;
}

