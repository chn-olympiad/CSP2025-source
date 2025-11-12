#include <bits/stdc++.h>
using namespace std;
int T, n;
int ans, x[100005], y[100005], z[100005];
struct node{
	int a, b, c;
} a[100005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("club.in", "r", stdin);	
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		int k = n / 2;
		for (int i = 1; i <= n; i++)
			cin >> a[i].a >> a[i].b >> a[i].c;
		int nx = 0, ny = 0, nz = 0, ans = 0; 
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(z, 0, sizeof(z));
		for (int i = 1; i <= n; i++)
		{
			if (a[i].a > a[i].b && a[i].a > a[i].c)
				x[i] = a[i].a, nx++;
			else if (a[i].b > a[i].a && a[i].b > a[i].c)
				y[i] = a[i].b, ny++;
			else z[i] = a[i].c, nz++;
		}	
		int maxc = -1;
		if (nx > k)
		{
			sort(x + 1, x + n + 1);
			for (int i = 1; i <= k; i++) ans += x[i];
			for (int i = 1; i <= n; i++) ans += y[i] + z[i]; 
			for (int i = 1; i <= nx - k; i++)
			{
				maxc = -1;
				for (int j = 1; j <= k; j++)
					maxc = max(maxc, max(a[j].b, a[j].c) + x[n / 2 + i] - a[j].a);
				ans += maxc;	
			}
		}
		else if (ny > k)
		{
			sort(y + 1, y + n + 1);
			for (int i = 1; i <= k; i++) ans += y[i];
			for (int i = 1; i <= n; i++) ans += x[i] + z[i]; 
			for (int i = 1; i <= ny - k; i++)
			{
				maxc = -1;
				for (int j = 1; j <= k; j++)
					maxc = max(maxc, max(a[j].a, a[j].c) + y[n / 2 + i] - a[j].b);
				ans += maxc;	
			}
		}
		else if (nz > k)
		{
			sort(z + 1, z + n + 1);
			for (int i = 1; i <= k; i++) ans += z[i];
			for (int i = 1; i <= n; i++) ans += y[i] + x[i]; 
			for (int i = 1; i <= nz - k; i++)
			{
				maxc = -1;
				for (int j = 1; j <= k; j++)
					maxc = max(maxc, max(a[j].b, a[j].a) + z[n / 2 + i] - a[j].c);
				ans += maxc;	
			}
		}	
		else
			for (int i = 1; i <= n; i++) ans += z[i] + y[i] + x[i];
		cout << ans << "\n";
	} 
	return 0;	
} 
