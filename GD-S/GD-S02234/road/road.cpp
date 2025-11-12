#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int p[N];
map <pair<int, int> > mp;

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]); 
	return p[x];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//后面只加cin跟cout!!!
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++) p[i] = i;
	for(int i = 1;i <= m;i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mp[{a, b}] = c;
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			if(mp[{i, j}] == 0) continue;
			if(find(i) != find(j))
			{
				ans += mp[{i, j}];
				p[i] = find(j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

