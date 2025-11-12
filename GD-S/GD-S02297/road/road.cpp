#include<iostream>
#include<algorithm>
#include<vector>
using std::cin;
using std::cout;
using std::sort;
using std::vector;
using std::min;

int n,m,k,fa[10015],a[11][10001];
long long ans = 0x3f3f3f3f3f3f3f3f;
bool used[15];

struct Edge{
	int u,v,w;
	bool operator < (const Edge &e) const
	{
		return w < e.w;
	}
}edge[1100005];

int find(int x){
	return fa[x] = (x == fa[x] ? x : find(fa[x]));
}

inline void uni(int x,int y){
	fa[find(y)] = find(x);
	return;
}

inline long long kruskal_base(){
	long long res = 0;
	int idx = 1,cnt = 0;
	for(int i = 1;i <= n;i += 1)
	{
		fa[i] = i;
	}
	sort(edge + 1,edge + 1 + m);
	while(idx <= m)
	{
		int u = edge[idx].u,v = edge[idx].v;
		if(find(u) != find(v))
		{
			cnt += 1;
			res += edge[idx].w;
			uni(u,v);
		}
		if(cnt == n - 1)
		{
			break;
		}
		idx += 1;
	}
	return res;
}

inline long long kruskal(){
	long long res = 0;
	int idx = 1,cnt = 0,n1 = n,m1 = m;
	for(int i = 1;i <= k;i += 1)
	{
		if(used[i])
		{
			n1 += 1;
			for(int j = 1;j <= n;j += 1)
			{
				m1 += 1;
				Edge temp = {n1,j,a[i][j]};
				edge[m1] = temp;
			}
		}
	}
	for(int i = 1;i <= n1;i += 1)
	{
		fa[i] = i;
	}
	sort(edge + 1,edge + 1 + m1);
	while(idx <= m1)
	{
		int u = edge[idx].u,v = edge[idx].v;
		if(find(u) != find(v) && u <= n1 && v <= n1)
		{
			cnt += 1;
			res += edge[idx].w;
			uni(u,v);
		}
		if(cnt == n1 - 1)
		{
			break;
		}
		idx += 1;
	}
	return res;
}

void dfs(int t,long long cst){
	if(t > k)
	{
		ans = min(ans,kruskal() + cst);
	}
	else
	{
		used[t] = true;
		dfs(t + 1,cst + a[t][0]);
		used[t] = false;
		dfs(t + 1,cst);
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	bool A = true;
	for(int i = 1;i <= m;i += 1)
	{
		cin>>u>>v>>w;
		Edge temp = {u,v,w};
		edge[i] = temp;
	}
	for(int i = 1;i <= k;i += 1)
	{
		for(int j = 0;j <= n;j += 1)
		{
			cin>>a[i][j];
		}
		if(a[i][0] != 0)
		{
			A = false;
		}
	}
	if(k == 0)
	{
		cout<<kruskal_base();
	}
	else if(A)
	{
		int idx = m;
		for(int i = 1;i <= k;i += 1)
		{
			for(int j = 1;j <= n;j += 1)
			{
				idx += 1;
				Edge temp = {i + n,j,a[i][j]};
				edge[idx] = temp;
			}
		}
		m = idx;
		n += k;
		cout<<kruskal_base();
	}
	else
	{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
