#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int w[N][5];
int sub_idx[5];
int mx[N], sec[N];
int cnt[5], sub[5][N];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t = 0;
	scanf("%d", &t);
	
	while (t -- )
	{
		sub_idx[1] = sub_idx[2] = sub_idx[3] = 0;
		
		scanf("%d", &n);
//		for (int i = 1; i <= n; ++ i )
//			
		int res = 0;
		for (int i = 1; i <= n; ++ i )
		{
			scanf("%d%d%d", &w[i][1], &w[i][2], &w[i][3]), w[i][0] = -1;
			
			mx[i] = sec[i] = 0;
			for (int j = 1; j <= 3; ++ j )
			{
				if (w[i][j] >= w[i][mx[i]])
				{
					sec[i] = mx[i];
					mx[i] = j;
					continue;
				}
				else if (w[i][j] > w[i][sec[i]])
					sec[i] = j;
				
//				if (t == 1)
//				{
//					printf("[%d, %d]: %d, %d\n", i, j, mx[i], sec[i]);
//				}
			}
			sub[mx[i]][ ++ sub_idx[mx[i]] ] = w[i][mx[i]] - w[i][sec[i]];
			
			res += w[i][mx[i]];
		}
		
//		for (int i = 1; i <= n; ++ i )
			
		
		sort(sub[1] + 1, sub[1] + sub_idx[1] + 1);
		sort(sub[2] + 1, sub[2] + sub_idx[2] + 1);
		sort(sub[3] + 1, sub[3] + sub_idx[3] + 1);
		
		if (sub_idx[1] > n / 2)
		{
			int limit = sub_idx[1] - n / 2;
			for (int i = 1; i <= limit; ++ i )
				res -= sub[1][i];
		}
		if (sub_idx[2] > n / 2)
		{
			int limit = sub_idx[2] - n / 2;
			for (int i = 1; i <= limit; ++ i )
				res -= sub[2][i];
		}
		if (sub_idx[3] > n / 2)
		{
			int limit = sub_idx[3] - n / 2;
			for (int i = 1; i <= limit; ++ i )
				res -= sub[3][i];
		}
		
//		for (int i = 1; i <= n; ++ i )
	}
	return 0;
}
