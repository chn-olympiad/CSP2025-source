#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 1.1e6 + 10;
int n,m,k;
class UF{
	private :
		vector <int> fa;
	public :
		UF (int n) : fa(n + 1)
		{
			for(int i = 1;i <= n;i++)
				fa[i] = i;
		}
		int find(int x)
		{
			if(x != fa[x])
				fa[x] = find(fa[x]);
			return fa[x];
		}
		bool unite(int x,int y)
		{
			int fx = find(x),fy = find(y);
			if(fx == fy)
				return false;
			fa[fx] = fy;
			return true;
		}
		bool check(int u,int v){return find(u) == find(v);}
};
struct edge{
	int u,v,w;
	bool operator < (const edge a) const
	{return w < a.w;}
};
int head[N],cnt; 
int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	UF s(n + k);
	edge e[m + k * n + 1];
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[i] = {u,v,w};
	}
	int cnt = m;
	for(int i = 1,c;i <= k;i++)
	{
		cin >> c;
		bool tf = false;
		for(int j = 1,w;j <= n;j++)
		{
			cin >> w;
			if(!tf)
				e[++cnt] = {i + n,j,c + w},
				tf = true;
			else
				e[++cnt] = {i + n,j,w};
		}
	}
//	for(int i = 1;i <= cnt;i++)
//		cout << e[i].u << ' ' << e[i].v <<' ' << e[i].w << '\n';
	sort(e + 1,e + cnt + 1);
	long long tot = 0,cnte = 0;
	bool fl = true;
	for(int i = 1;i <= m + k * n;i++)
	{
		int u = e[i].u,v = e[i].v;
		if(u > n)
			fl = (fl ? false : true);
		if(s.unite(u,v))
			cnte++,tot += e[i].w;
		if(cnte == n - 1 && fl)
			break;
	}
	cout << tot;
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
