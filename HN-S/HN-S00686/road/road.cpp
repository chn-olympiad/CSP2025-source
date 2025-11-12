#include <bits/stdc++.h>
using namespace std;
int n , m , k;
vector <int> v[10005];
int a[10015][10015];
int s[10015];
void bfs()
{
	memset(s , 0x3f , sizeof(s));
	queue <int> q;
	q.push(1);
	s[1] = 0;
	for (int i = 0; i < v[1].size(); i++)
	{
		int x = v[1][i];
		q.push(x);
		s[i] = min(s[i] , a[1][i]);
	}
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 0; i < v[k].size(); i++)
		{
			int x = v[k][i];
			if (s[k] + a[k][x] < s[x])
			{
				s[x] = s[k] + a[k][x];
				q.push(x);
			}
		}
	}
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u , x , w;
		cin >> u >> x >> w;
		v[u].push_back(x);
		v[x].push_back(u);
		a[u][x] = a[x][u] = w;
	}
	for (int i = m + 1; i <= m + k; i++)
	{
		int jj;
		cin >> jj;
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(j);
			v[j].push_back(i);
			a[i][j] = a[j][i] = x; 
		}
	}
	
	bfs();
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += s[i];
	}
	cout << ans;
	return 0;
 } 
