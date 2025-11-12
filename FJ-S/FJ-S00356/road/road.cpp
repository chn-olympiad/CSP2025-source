#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5,
inf = 1e18,M = 2e4 + 5;
int n,m,k,c[N];
int cnt,vis[M];
int fa[N];
struct node
{
	int u,v,w;
}a[N];

inline int cmp(node x,node y)
{
	return x.w <y.w;
}

inline int find(int k)
{
	if(fa[k] == k) return k;
	return fa[k] = find(fa[k]);
}

inline int solve(int mx)
{
	int tot = n,ans = 0;
	for(int i = 1; i <= k; i++)
	{
		if(mx >> (i - 1) & 1)
		{
			vis[i+n] = 1;
			fa[i +n] = i +n;
			tot++;
			ans += c[i];
		}
		else vis[i +n] = 0;
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
		//cout << ans<<  "\n";
	//cout << tot << "\n";
	//for(int i = 1; i <= n +k; i++)
	//	cout << vis[i] << " ";
	//cout<< "\n";
	for(int i = 1; i <= cnt; i++)
	{
		int u = a[i].u,v = a[i].v;
		if(!vis[a[i].u] || !vis[a[i].v]) continue;
		u = find(u),v = find(v);
		if(u == v) continue;
		fa[u] = v; ans += a[i].w;
		--tot;
		//cout << tot << "\n";
		//cout << a[i].w <<"\n";
		if(tot == 1) 
			return ans;
	}
	return ans;
}

inline int read()
{
	int res = 0;
	char a = getchar();
	while(a >= '0' && a <= '9')
		res = (res << 3) + (res << 1) + (a ^ 48),
		a = getchar();
	return res;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//double st = time(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	n = read(); m = read();
	k = read();
	
	//cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		//int u,v,w;
		//cin >> u >> v >> w;
		int u = read(),v = read(),
		w = read();
		a[i] = {u,v,w};
	}
	
	cnt = m;
	int pd = 0;
	for(int i = 1; i <= k; i++)
	{
		//cin >> c[i]; 
		c[i] = read(); pd |= c[i];
		for(int j = 1; j <= n; j++)
		{
			int w = read();
			//int w; cin >> w;
			a[++cnt] = {i + n,j,w};
			pd |= w;
		}
	}
	//cout << cnt <<"\n";
	if(!pd)
	{
		cout << 0;
		return 0;
	}
	sort(a + 1,a + 1 +cnt,cmp);
	//for(int i = 1; i <= cnt; i++)
	//	cout << a[i].w <<"\n";
	for(int i = 1; i <= n; i++)
		vis[i] = 1;
		
	int ans = inf;
	//cout <<solve(1);
	//solve(0);
	for(int i = 0; i < (1 << k); i++)
		//cout << 0 << " " << solve(0) << "\n"; 
		ans = min(ans,solve(i));
	cout << ans;
	//cout << ans <<"\n";
	//double ed = time(0);
	//cout << double(ed - st) << "\n";
}
