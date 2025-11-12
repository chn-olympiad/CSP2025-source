#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6 + 10, M = 1e12;
inline int read()
{
	char c; int sign = 1, res = 0;
	while((c = getchar()) > '9' || c < '0')
	{
		if(c == '-') sign = -1;
	}
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * sign;
}
int go[N], w[N], nxt[N], head[N], tot;
int n, m, k;
int d[N], ex[N];
int pre[N];
void add(int xx, int yy, int zz)
{
	nxt[++tot] = head[xx];
	go[tot] = yy;
	w[tot] = zz;
	head[xx] = tot;
}
struct node
{
	int val, u, rt;
	bool operator < (const node tmpp) const
	{
		return val > tmpp.val;
	}
}tp;
priority_queue<node> pq;
bool vis[N];
void solve()
{
	int res, ans = M;
	for(int j = 0; j < (1 << k); j++)
	{
		//cout << j << "%:";
		res = 0;
		memset(d, 0x3f3f3f, sizeof(d));
		memset(vis, 0, sizeof(vis));
		d[1] = pre[j];
		if(pre[j] > ans) continue;
		pq.push(node{pre[j], 1, pre[j]});
		while(!pq.empty())
		{
			tp = pq.top(); pq.pop();
			int u = tp.u;
			while(vis[u] && !pq.empty())
			{
				tp = pq.top();
				pq.pop();
				u = tp.u;
			}
			if(vis[u] && pq.empty()) break;
			//cout << u << " ";
			vis[u] = 1;
			for(int i = head[u]; i; i = nxt[i])
			{
				int v = go[i];
				//value = w[i];
				int nw = 1 << (v - n - 1);
				if(vis[v] || (!(j & nw) && v > n)) continue;
				if(d[v] > w[i])
				{
					d[v] = w[i];
					if(tp.rt + w[i] < ans)
						pq.push(node{w[i], v, tp.rt + w[i]});
				}
			}
			//cout << d[u] << endl;
		}
		for(int i = 1; i <= n; i++)
		{
			res += d[i];
			//cout << d[i] << " ";
		}
		for(int i = 0; i < k; i++)
		{
			if((1 << i) & j) res += d[i + n + 1];
		}
		ans = min(ans, res);
		//cout << ans << endl;
	}
	
	//cout << endl;
	cout << ans;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; i++)
	{
		int xx, yy, zz; xx=read();yy=read();zz=read();
		add(xx, yy, zz);add(yy, xx, zz);
	}
	for(int i = 1; i <= k; i++)
	{
		int indx = i + n, zz;
		ex[i] = read();
		for(int j = 1; j <= n; j++)
		{
			zz = read();
			add(j, indx, zz);
			add(indx, j, zz);
		}
	}
	for(int i = 0; i < (1 << k); i++)
	{
		for(int j = 0; j < k; j++)
		{
			if(i & (1 << j)) pre[i] += ex[j + 1];
		}
	}
	solve();
	return 0;
}
