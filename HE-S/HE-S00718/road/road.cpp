#include<bits/stdc++.h>
using namespace std; 
#define LL long long

const int N = 1e4 + 100, M = 2e6 + 5, K = 15;

int n, m, k, p[N], lc, rc;
bool vis[K];
LL c[K], ac[K][N];
struct node
{
	int u, v;
	LL w;
	bool operator <(const node &a) const
	{
		return w < a.w;
	}
} edge[M], dk[M];

int _find(int x)
{
	if(p[x] != x) return p[x] = _find(p[x]);
	return x;
}

vector<int> q[K];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	cin >> n >> m >> k;
	
	int a, b; LL g;
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b >> g;
		dk[i] = edge[i] = (node){a, b, g};	
	}
	
	lc = 0;
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++)
		{
			if(j == 0)
			{
				cin >> c[i];
				if(c[i] == 0) lc++;
			} 
			else
			{
				cin >> ac[i][j];
				if(!vis[i] && ac[i][j] == 0)
				{
					rc++;
					vis[i] = true;
				}
			}
		}
	
	if(lc == k && rc == k)
	{
		int l = (1 << k) - 1;
		for(int i = 1; i <= n + k; i++) p[i] = i;
		
		int tot = m, cnt = 0, num = n; LL sum = 0;
		for(int i = 0; i < k; i++)
		{
			if(l & (1 << i)) 
			{
				num++;
				sum += c[i + 1];
				for(int j = 1; j <= n; j++)
					edge[++tot] = (node){n + i + 1, j, ac[i + 1][j]};
			}
		}
		
		sort(edge + 1, edge + tot + 1);
		
		for(int i = 1; i <= tot; i++)
		{
			int u = edge[i].u, v = edge[i].v;
			LL w = edge[i].w;
			
			int x = _find(u), y = _find(v);
			if(x == y) continue;
			
			p[x] = y;
			sum += w;
			cnt++;
			if(cnt == num - 1) break;
		}
		
		cout << sum << "\n";
		return 0;
	}
	
	LL ans = 1e18;
	for(int l = 0; l < (1 << k); l++)
	{
		for(int i = 1; i <= n + k; i++) p[i] = i;
		
		int tot = m, cnt = 0, num = n; LL sum = 0;
		for(int i = 0; i < k; i++)
		{
			if(l & (1 << i)) 
			{
				num++;
				sum += c[i + 1];
				for(int j = 1; j <= n; j++)
					edge[++tot] = (node){n + i + 1, j, ac[i + 1][j]};
			}
		}
		
		sort(edge + 1, edge + tot + 1);
		
		for(int i = 1; i <= tot; i++)
		{
			int u = edge[i].u, v = edge[i].v;
			LL w = edge[i].w;
			
			int x = _find(u), y = _find(v);
			if(x == y) continue;
			
			p[x] = y;
			sum += w;
			cnt++;
			if(cnt == num - 1) break;
		}
		
		ans = min(ans, sum);
	}
	
	cout << ans << "\n";	
} 
