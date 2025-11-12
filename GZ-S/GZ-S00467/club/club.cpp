//GZ-S00467 华中师大一附中贵阳学校 陈思佟 
#include <bits/stdc++.h>

//#define int long long
#define endl '\n'

using namespace std;

const int N = 1e5+10;
int n;
int ans, num, dx1, dx2, dx3;
struct person
{
	int a, b, c;
	int id;
	int se;
} w[N];
int club[N][3], idx[3];

inline int work1(int i)
{
	int a = w[i].a, b = w[i].b, c = w[i].c;
	
	if (a >= b && a >= c)
		return 0;
	if (b >= a && b >= c)
		return 1;
	if (c >= a && c >= b)
		return 2;
}

inline int work2(int i)
{
	int a = w[i].a, b = w[i].b, c = w[i].c;
	return max(a, max(b, c));
}

inline int work3(int i, int k)
{
	if (k == 0)
		return w[i].a;
	if (k == 1)
		return w[i].b;
	if (k == 2)
		return w[i].c;
}

inline int work4(int i)
{
	int a = w[i].a, b = w[i].b, c = w[i].c;
	
	if (a == b && a == c && b == c)
		return 3;
	if ( ((a <= b && a >= c) || (a >= b && a <= c)) && work1(i) != 0)
		return 0;
	if ( ((b <= a && b >= c) || (b >= a && b <= c)) && work1(i) != 1)
		return 1;
	if ( ((c <= a && c >= b) || (c >= a && c <= b)) && work1(i) != 2)
		return 2;
}

inline int work5(int i)
{
	int a = w[i].a, b = w[i].b, c = w[i].c;
	
	if (a <= b && a <= c)
		return 0;
	if (b <= a && b <= c)
		return 1;
	if (c <= a && c <= b)
		return 2;
}

inline void dfs (int u)
{
	if (u > n)
	{
		ans = max(ans, num);
		return;
	}
	
	if (dx1 < n / 2)
	{
		dx1 ++;
		num += w[u].a;
		dfs(u + 1);
		num -= w[u].a;
		dx1 --;
	}
	
	if (dx2 < n / 2)
	{
		dx2 ++;
		num += w[u].b;
		dfs(u + 1);
		num -= w[u].b;
		dx2 --;
	}
	
	if (dx3 < n / 2)
	{
		dx3 ++;
		num += w[u].c;
		dfs(u + 1);
		num -= w[u].c;
		dx3 --;
	}
}

inline int solve1()
{
	ans = num = dx1 = dx2 = dx3 = 0;
	dfs (1);
	cout << ans << endl;
}

inline bool cmp1(person x, person y)
{
	return x.a > y.a;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while (T --)
	{
		//init();
		idx[0] = idx[1] = idx[2] = 0;
		cin >> n;
		
		bool mk1 = true, mk2 = true;
		for (int i = 1; i <= n; i ++)
		{
			cin >> w[i].a >> w[i].b >> w[i].c;
			if (w[i].b != 0 || w[i].c)
				mk1 = false;
			if (w[i].c != 0)
				mk2 = false;
		}
		
		if (n <= 10)
		{
			solve1();
			continue;
		}
		
		if (mk1)
		{
			int sum = 0;
			sort(w + 1, w + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i ++)
			{
				sum +=  w[i].a;
			}
			cout << sum << endl;
			continue;
		}
		
		for (int i = 1; i <= n; i ++)
		{
			w[i].se = work4(i);
			
			int moss = work1(i);
			if (idx[moss] < n / 2)
			{
				club[++ idx[moss]][moss] = i;
			}
			else
			{
				bool mk = false;
				for (int j = 1; j <= idx[moss]; j ++)
				{
					int xb = club[j][moss];
					for (int k = 0; k < 3; k ++)
						if (work2(i) + work3(xb, k) > work3(xb, moss)&& k != moss && k != work5(i))//(k == w[xb].se || w[xb].se == 3)
						{
							club[++ idx[k]][k] = j;
							club[j][moss] = i;
							mk = true;
							break;
						}
					
					if (mk) break;
				}
				
				if (!mk)
				{
					int moss2 = w[i].se;
					club[++ idx[moss2]][moss2] = i;
				}
			}
			//w[i].id = i;
		}
		
		int res = 0;
		for (int k = 0; k < 3; k ++)
		{
			for (int i = 1; i <= idx[k]; i ++)
			{
				res += work3(club[i][k], k);
			}
		}
		
		cout << res << endl;
	}
	
	return 0;
}
