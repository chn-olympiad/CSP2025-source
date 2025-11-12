#include <bits/stdc++.h>
using namespace std;

namespace ljw
{
	const int N = 2e5 + 10;
	vector<int> st[3], backup[3];
	int n, res1, res2;
	
	struct Cow
	{
		int a, b, c, id;
	} g[N];
	
	inline bool cmp(Cow x, Cow y)
	{
		return max({x.a, x.b, x.c}) < max({y.a, y.b, y.c});
	}
	
	inline bool cmp1(int x, int y)
	{
		return g[x].a < g[y].a;
	}
	
	inline bool cmp2(int x, int y)
	{
		return g[x].b < g[y].b;
	}
	
	inline bool cmp3(int x, int y)
	{
		return g[x].c < g[y].c;
	}
	
	inline bool cmpv1(int x, int y)
	{
		return g[x].a > g[y].a;
	}
	
	inline bool cmpv2(int x, int y)
	{
		return g[x].b > g[y].b;
	}
	
	inline bool cmpv3(int x, int y)
	{
		return g[x].c > g[y].c;
	}
	
	void solve1()
	{
		int len1 = st[0].size(), len2 = st[1].size(), len3 = st[2].size();
		if (len1 > n / 2)
		{
			sort(st[0].begin(), st[0].end(), cmp1);
			
			for (int i = n / 2; i < len1; i++)
			{
				int now = st[0][i];
				
				if (g[now].b > g[now].c)
					st[1].push_back(now);
				else
					st[2].push_back(now);
			}
			
			for (int i = n / 2; i < len1; i++)
				st[0].pop_back();
		}
		
		if (len2 > n / 2)
		{
			sort(st[1].begin(), st[1].end(), cmp2);
			
			for (int i = n / 2; i < len2; i++)	
			{
				int now = st[1][i];
				
				if (g[now].a > g[now].c)
					st[0].push_back(now);
				else
					st[2].push_back(now);
			}
			
			for (int i = n / 2; i < len2; i++)
				st[1].pop_back();
		}
		
		if (len3 > n / 2)
		{
			sort(st[2].begin(), st[2].end(), cmp3);
			
			for (int i = n / 2; i < len3; i++)	
			{
				int now = st[2][i];
				
				if (g[now].b > g[now].a)
					st[1].push_back(now);
				else
					st[0].push_back(now);
			}
			
			for (int i = n / 2; i < len3; i++)
				st[2].pop_back();
		}
		
		for (auto i : st[0])
			res1 += g[i].a;
	
		for (auto i : st[1])
			res1 += g[i].b;
			
		for (auto i : st[2])
			res1 += g[i].c;
	}
	
	void solve2()
	{
		int len1 = st[0].size(), len2 = st[1].size(), len3 = st[2].size();
		if (len1 > n / 2)
		{
			sort(st[0].begin(), st[0].end(), cmpv1);
			
			for (int i = n / 2; i < len1; i++)
			{
				int now = st[0][i];
				
				if (g[now].b > g[now].c)
					st[1].push_back(now);
				else
					st[2].push_back(now);
			}
			
			for (int i = n / 2; i < len1; i++)
				st[0].pop_back();
		}
		
		if (len2 > n / 2)
		{
			sort(st[1].begin(), st[1].end(), cmpv2);
			
			for (int i = n / 2; i < len2; i++)	
			{
				int now = st[1][i];
				
				if (g[now].a > g[now].c)
					st[0].push_back(now);
				else
					st[2].push_back(now);
			}
			
			for (int i = n / 2; i < len2; i++)
				st[1].pop_back();
		}
		
		if (len3 > n / 2)
		{
			sort(st[2].begin(), st[2].end(), cmpv3);
			
			for (int i = n / 2; i < len3; i++)	
			{
				int now = st[2][i];
				
				if (g[now].b > g[now].a)
					st[1].push_back(now);
				else
					st[0].push_back(now);
			}
			
			for (int i = n / 2; i < len3; i++)
				st[2].pop_back();
		}
		
		for (auto i : st[0])
			res2 += g[i].a;
	
		for (auto i : st[1])
			res2 += g[i].b;
			
		for (auto i : st[2])
			res2 += g[i].c;
	}
	
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);

		int t;
		cin >> t;
		
		while (t--)
		{
			cin >> n;
			
			st[0].clear();
			st[1].clear();
			st[2].clear();
			
			for (int i = 1; i <= n; i++)
				cin >> g[i].a >> g[i].b >> g[i].c;
			
			sort(g + 1, g + n + 1, cmp);
			
			for (int i = 1; i <= n; i++)
			{
				if (g[i].a > g[i].b && g[i].a > g[i].c)
					st[0].push_back(i);
					
				if (g[i].b > g[i].a && g[i].b > g[i].c)
					st[1].push_back(i);
					
				if (g[i].c > g[i].a && g[i].c > g[i].b)
					st[2].push_back(i);
				
				g[i].id = i;
			}
			
			backup[0] = st[0];
			backup[1] = st[1];
			backup[2] = st[2];
			
			res1 = res2 = 0;
			
			solve1();
			
			st[0] = backup[0];
			st[1] = backup[1];
			st[2] = backup[2];
			
			solve2();
			
			cout << max(res1, res2) << '\n';
		}
		
		
		return 0;
	}
}

int main()
{
	return ljw::main();
}
/*
#include <bits/stdc++.h>
using namespace std;

namespace ljw
{
	const int N = 2e5 + 10;
	int g[N][3];
	int f[N][3], st[N][3][3];
	
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);

		int t;
		cin >> t;
		
		int n;
		while (t--)
		{
			cin >> n;
			
			memset(f, 0, sizeof f);
			memset(st, 0, sizeof st);
			
			for (int i = 1; i <= n; i++)
				cin >> g[i][0] >> g[i][1] >> g[i][2];
			
			f[1][0] = g[1][0];
			f[1][1] = g[1][1];
			f[1][2] = g[1][2];
			
			st[1][0][0] = st[1][1][1] = st[1][2][2] = 1;
			
			for (int i = 2; i <= n; i++)
				for (int j = 0; j < 3; j++)
				{
					bool flag = false;
					for (int k = 0; k < 3; k++)
						if (st[i - 1][k][j] < n / 2)
							if (f[i - 1][k] > f[i][j])
							{
								flag = true;
								f[i][j] = f[i - 1][k];
								
								st[i][j][0] = st[i - 1][k][0];
								st[i][j][1] = st[i - 1][k][1];
								st[i][j][2] = st[i - 1][k][2];
							}
							
					if (flag)
					{
						f[i][j] += g[i][j];
						st[i][j][j]++;
					}
				}
				
			cout << max({f[n][0], f[n][1], f[n][2]}) << '\n';
		}
		
		
		return 0;
	}
}

int main()
{
	return ljw::main();
}
*/
