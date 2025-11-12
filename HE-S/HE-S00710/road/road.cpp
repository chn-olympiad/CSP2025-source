#include<bits/stdc++.h>
#define int long long 
#define Blue_Archive return 0
using namespace std;
constexpr int N = 1e4 + 7;
constexpr int M = 1e6 + 7;
constexpr int INF = 1e18;

int n;
int m;
int k; 
int ans;
int c[13];
int fa[N];
int stk[N];
int v[13][N];

struct miku
{
	int u,v,w;
	friend bool operator < (miku a,miku b){return a.w < b.w;}
}e[M],a[N],tmp[N * 12];

inline int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}

inline int check(int top) // O(n log_2{n})
{
	int siz = n - 1,res = 0;
	for(int i = 1;i < n;i ++) tmp[i] = a[i];
	for(int i = 1;i <= top;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			tmp[++ siz] = {i + n,j,v[stk[i]][j]};
		}
	}
	sort(tmp + 1,tmp + siz + 1);
	for(int i = 1;i <= n + top;i ++) fa[i] = i;
	for(int i = 1,p,q,cnt = 0;i <= siz;i ++)
	{
		p = find(tmp[i].u);
		q = find(tmp[i].v);
		if(p == q) continue;
		fa[p] = q;
		res += tmp[i].w;
		cnt ++;
		if(cnt == n + top - 1) break;
	}
	return res;
}

inline void dfs(int x,int sum,int res) // O(2 ^ k)
{
	if(sum >= ans) return;
	if(x == k + 1)
	{
		ans = min(ans,check(res) + sum);
		return;
	}
	dfs(x + 1,sum,res);
	stk[res + 1] = x;
	dfs(x + 1,sum + c[x],res + 1);
}

signed main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	// freopen("data.in","r",stdin);freopen("data.out","w",stdout);    
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++) fa[i] = i;
	for(int i = 1,u,v,z;i <= m;i ++)
	{
		cin >> u >> v >> z;
		e[i] = {u,v,z};
	}
	for(int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++) cin >> v[i][j];
	}
	ans = 0;
	sort(e + 1,e + m + 1);
	for(int i = 1,p,q,cnt = 0;i <= m;i ++)
	{
		p = find(e[i].u);
		q = find(e[i].v);
		if(p == q) continue;
		fa[p] = q;
		ans += e[i].w;
		stk[++ cnt] = i; 
		if(cnt == n - 1) break;
	}
	for(int i = 1;i < n;i ++) a[i] = e[stk[i]];
	dfs(1,0,0);
	cout << ans << '\n';
	Blue_Archive;
}