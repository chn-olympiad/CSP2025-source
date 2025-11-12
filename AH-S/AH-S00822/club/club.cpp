#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, INF = 2e9;

int t, n, ans;
int b[N];
int f[210][210][210];
struct node
{
	int x, y, z;
}a[N];
vector<int> A, B, C;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while (t -- )
	{
		scanf("%d", &n); bool flag = 1;
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			if(a[i].z != 0) flag = 0;
		}
		if(n <= 200)
		{
			memset(f, -0x3f, sizeof f);
			f[0][0][0] = 0; ans = 0;
			for (int i = 1; i <= n; i ++ )
				for (int x = 0; x <= min(n / 2, i); x ++ )
					for (int y = 0; y <= min(n / 2, i - x); y ++ )
					{
						int z = i - x - y;
						if(z > n / 2) continue;;
						int f1 = -0x3f3f3f3f, f2 = -0x3f3f3f3f, f3 = -0x3f3f3f3f;
						if(x > 0) 
							f1 = f[i - 1][x - 1][y] + a[i].x;
						if(y > 0)
							f2 = f[i - 1][x][y - 1] + a[i].y;
						if(z > 0)
							f3 = f[i - 1][x][y] + a[i].z;
						f[i][x][y] = max(f1, max(f2, f3));
						ans = max(ans, f[i][x][y]);
					}
			printf("%d\n", ans);
			continue;
		}
		else if(flag == 1)
		{
			int ans = 0, siza = 0, sizb = 0;
			for (int i = 1; i <= n; i ++ )
			{
				if(a[i].x > a[i].y) ans += a[i].x, siza ++;
				else ans += a[i].y, sizb ++;
			}
			if(siza > n / 2)
			{
				for (int i = 1; i <= n; i ++ )
					if(a[i].x > a[i].y) b[i] = a[i].x - a[i].y;
					else b[i] = INF;
				sort(b + 1, b + n + 1);
				for (int i = 1; i <= siza - n / 2; i ++ ) ans -= b[i];
			}
			if(sizb > n / 2)
			{
				for (int i = 1; i <= n; i ++ )
					if(a[i].y >= a[i].x) b[i] = a[i].y - a[i].x;
					else b[i] = INF;
				sort(b + 1, b + n + 1);
				for (int i = 1; i <= sizb - n / 2; i ++ ) ans -= b[i];
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
