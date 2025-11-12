#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
struct node1{int v, w;};
struct node2{int u, v, w;};
vector<node1> edge[MAXN];
int c1[15], a1[15][MAXN], f[MAXN];
node2 s[MAXN * 100];
long long ans;
int n, m, k, u, v, w;
bool cmp(node2 x, node2 y){return x.w < y.w;}
int find(int x)
{
	if(f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
void merge(int x, int y)
{
	f[find(x)] = find(y);
	return;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		cin >> u >> v >> w;
		s[i].u = u;
		s[i].v = v;
		s[i].w = w;
	}
//	cout << "||||||||||" << endl;
	for(int i = 1; i <= k; i ++)
	{
		cin >> c1[i];
		for(int j = 1; j <= n; j ++)
		{
			cin >> a1[i][j];//总计最多10^5条额外边 
		}
	}
	for(int i = 1; i <= k; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			m ++;
			s[m].u = i + n;
			s[m].v = j;
			s[m].w = a1[i][j];
		}
	}
	for(int i = 1; i <= k; i ++)
	{
		ans += c1[i];
	}
	sort(s + 1, s + m + 1, cmp);
	for(int i = 1; i <= n + k; i ++) f[i] = i;
	int cur = 0;
	while(cur < m)
	{
		cur ++;
		if(find(s[cur].u) == find(s[cur].v)) continue;
		ans += s[cur].w;
		merge(s[cur].u, s[cur].v); 
	}
	cout << ans << endl;
	return 0;
}
//密码：Ren5Jie4Di4Ling5%
