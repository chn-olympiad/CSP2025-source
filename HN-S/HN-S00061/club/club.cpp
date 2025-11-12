#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long T;
struct Node{
	long long x, y, z;
}a[N], b[N];
bool vis[N];
long long s[N];
bool cmp1(Node a, Node b)
{
	return a.x > b.x;
}
bool cmp2(Node a, Node b)
{
	return (a.x - a.y) < (b.x - b.y); 
}
void solve()
{
	memset(s, 0, sizeof(s));
	memset(vis, 0, sizeof(vis));
	long long n;
	cin >> n;
	long long m = n / 2;
	bool af = 0, bf = 0;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
		if (a[i].y != 0)
			af = 1;
		if (a[i].z != 0)
			bf = 1;
	}
	if (af == 0 && bf == 0)
	{
		long long sum = 0;
		sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= m; ++ i)
			sum += a[i].x;
		cout << sum << "\n";
	}
	else if (bf == 0)
	{
		sort(a + 1, a + n + 1, cmp2);
		long long sum = 0;
		for (int i = 1; i <= n; ++ i)
		{
			sum += a[i].x;
			s[i] = s[i - 1] + (a[i].x - a[i].y);
		}
		long long maxn = 0;
		for (int k = 1; k <= m; ++ k)
		{
			long long len = n - k;
			if (len > m)
				continue;
			maxn = max(maxn, sum - s[len]);
		}
		cout << maxn << "\n";
	}
	else if (n == 2)
	{
		long long sum = 0, ans = 0;
		for (int i = 1; i <= 3; ++ i)
		{
			for (int j = 1; j <= 3; ++ j)
			{
				if (i == j)
					continue; 
				if (i == 1)
					sum += a[1].x;
				if (j == 1)
					sum += a[2].x;
				if (i == 2)
					sum += a[1].y;
				if (j == 2)
					sum += a[2].y;
				if (i == 3)
					sum += a[1].z;
				if (j == 3)
					sum += a[2].z;
				ans = max(ans, sum);
				sum = 0; 
			} 
		}
		cout << ans << "\n";
	}
	else if (n == 4)
	{
		long long sum = 0, ans = 0;
		for (int i = 1; i <= 3; ++ i)
		{
			for (int j = 1; j <= 3; ++ j)
			{
				for (int k = 1; k <= 3; ++ k)
				{
					for (int p = 1; p <= 3; ++ p)
					{
						if ((i == j && j == k)||(i == j && j == p)||(i == k && k == p)||(j == k && k == p))
							continue; 
						if (i == 1)
							sum += a[1].x;
						if (j == 1)
							sum += a[2].x;
						if (i == 2)
							sum += a[1].y;
						if (j == 2)
							sum += a[2].y;
						if (i == 3)
							sum += a[1].z;
						if (j == 3)
							sum += a[2].z;
						if (k == 1)
							sum += a[3].x;
						if (p == 1)
							sum += a[4].x;
						if (k == 2)
							sum += a[3].y;
						if (p == 2)
							sum += a[4].y;
						if (k == 3)
							sum += a[3].z;
						if (p == 3)
							sum += a[4].z;
						ans = max(ans, sum);
						sum = 0; 
					}
				}
			} 
		}
		cout << ans << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T --)
		solve();
	return 0;
}
