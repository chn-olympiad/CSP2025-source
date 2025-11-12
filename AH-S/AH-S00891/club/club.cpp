#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll T, n, k;
struct node
{
	int x, y, z;
}a[N];
int h[100005];
struct node1
{
	int num, x, y;
}b[100005];
int tot = 0;
bool cmp(node1 x, node1 y)
{
	return x.num < y.num;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			b[++tot].num = a[i].x, b[tot].x = i, b[tot].y = 1;
			b[++tot].num = a[i].y, b[tot].x = i, b[tot].y = 2;
			b[++tot].num = a[i].z, b[tot].x = i, b[tot].y = 3;
		}
		sort (b + 1, b + tot + 1, cmp);
		int sum = 0, ans = 0;
		int g[4] = {0};//g is for y, h is for x;
		memset(h, 0, sizeof h);
		for (int i = tot; i >= 1; i--)
		{
			if (g[b[i].y] < n / 2 && !h[b[i].x])
			{
				
				g[b[i].y]++;
				h[b[i].x]++;
				ans += b[i].num;
				sum++;
			}
			if (sum >= n) break;
		}
		cout << ans << endl; 
	}
	
	return 0;       
}
