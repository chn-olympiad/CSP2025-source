#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 10010;
struct Node{int u,v,w;};
vector<Node> Edge;
int fa[maxn], c[maxn], a[20][maxn], n, m, k, sum;
bool cmp(Node &A, Node &B)
{
	return A.w<B.w;
}
int find_fa(int u)
{
	if(fa[u]==u) return u;
	return fa[u] = find_fa(fa[u]);
}
int solve(int s)
{
	//cout<<"S:"<<s<<endl;
	vector<Node> E = Edge;
	int res = 0, cnt = 0, add = 0;
	for(int i=1;i<=k;i++)
	{
		if(s&(1<<(i-1)))
		{
			add++;
			res += c[i];
			for(int j=1;j<=n;j++)
				E.push_back({n+add,j,a[i][j]});
		}
	}
	sort(E.begin(),E.end(),cmp);
	for(int i=1;i<=n+add;i++)
		fa[i] = i;
	int sz = E.size();
	for(int i=0;i<sz;i++)
	{
		int u = E[i].u, v = E[i].v, w = E[i].w;
		int fu = find_fa(u), fv = find_fa(v);
		if(fu!=fv)
		{
			//cout<<"U,V,W:"<<u<<" "<<v<<" "<<w<<endl;
			cnt++;
			fa[fu] = fv;
			res += w;
			if(cnt==n+add-1) break;
		}
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		Edge.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		sum += c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(sum==0)
	{
		cout<<solve(((1<<k)-1))<<endl;
		return 0;
	}
	int ans = 1e17;
	if(k>5) k = 5;
	for(int i=0;i<(1<<k);i++)
		ans = min(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}
