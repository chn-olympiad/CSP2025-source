#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define ms(a,b) memset(a,b,sizeof(a))
#define lowbit(x) x&(-x)
#define mk make_pair


inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch >'9' || ch < '0')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x*f;
}

int n, m, k;
struct nod
{
	int x, z;
};
vector<nod> adj[150010];
int c[20];
int a[20][10010];

//1
struct node
{
	int x, y, z;
}f[2000010];
int tot;

inline bool cmp(node u, node v)
{
	return u.z < v.z;
}
int fu[10010];
inline int find(int x)
{
	return x == fu[x] ? x : (fu[x] = find(fu[x]));
}

//bool flag[10510];

inline solve1()
{
	sort(f+1,f+1+tot,cmp);
	int ans = 0, t = 0;
//	int num = n;
//	for(int i = 1;i <= n;++i) flag[i] = 1;
	for(int i = 1;i <= m;++i)
	{
		int fx = find(f[i].x), fy = find(f[i].y);
		if(fx != fy)
		{
			fu[fx] = fy;
			++t;
//			if(!flag[f[i].x]) flag[f[i].x] = 1, ++num;
//			if(!flag[f[i].y]) flag[f[i].y] = 1, ++num;
			ans += f[i].z;
		}
		if(t == n-1) break;
	}
	cout << ans;
}

int ans = 1e18;
bool flag[10510];

inline void dfs(int u, int h, int t, int s)
//		当前位置、在第几层、已经到达了多少点，花费的钱 
{
	if(t == n)
	{
		ans = min(ans,s);
		return;
	}
	if(!h)
	{
		for(auto p : adj[u])
		{
			int v = p.x;
			if(!flag[v])
			{
				flag[v] = 1;
				if(v <= n) dfs(v,h,t+1,s+p.z);
				else dfs(v,v-n,t,s+p.z);
				flag[v] = 0;
			}
		}
	}
	else
	{
		for(int i = 1;i <= n+k;++i)
		{
			if(!flag[i])
			{
				flag[i] = 1;
				if(i <= n) dfs(h*n+k+i,h,t+1,s+a[h][i]);
				else dfs(i,i-n,t,s+c[i-n]);
				flag[i] = 0;
			}
		}
	}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	bool A = 0;
	for(int i = 1;i <= m;++i)
	{
		int u = read(), v = read(), w = read();
		f[i].x = u, f[i].y = v, f[i].z = w;
		nod t;
		t.x = v;
		t.z = w;
		adj[u].pb(t);
		t.x = u;
		adj[v].pb(t);
	}
	tot = m;
	for(int i = 1;i <= k;++i)
	{
		c[i] = read();
		if(c[i]) A = 1;
		for(int j = 1;j <= n;++j)
		{
			int temp = read();
			a[i][j] = temp;
//			f[++tot] = {n+i,j,c[i]};
//			f[++tot] = {n+i,j,temp};
			adj[j].pb({n+i,c[i]});
//			adj[i+n].pb({i*n+k+j,temp});
		}
	}
	for(int i = 1;i <= n+k;++i) fu[i] = i;
	if(!k)
	{
		solve1();
		return 0;
	}
//	for(int i = 1;i <= k;++i)
//	{
//		for(int j = 1;j <= k;++j)
//		{
//			if(i == j) continue;
//			for(int l = 1;l <= n;++l) adj[i*n+k+l].pb({n+j,c[j]});
//		}
//	}
	for(int i = 1;i <= n;++i)
	{
		ms(flag,0);
//		flag[i] = 1;
		dfs(i,0,0,0);
	}
	cout << ans;
	return 0;
}
