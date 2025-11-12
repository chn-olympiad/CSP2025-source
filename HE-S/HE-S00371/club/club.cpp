#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, n;
int cnt[5];
int a[5][N];
int dp[5][N], vis[5][N];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T --)
	{
		cin >> n;
		int n2 = n / 2;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= 3; j ++)
			{
				scanf("%d", &a[j][i]);
			}
		}
		int s1 = 0, s2 = 0, s3 = 0;
		for(int i = 1; i <= n; i ++)
		{
			s1 += a[1][i];
			s2 += a[2][i];
			s3 += a[3][i];
		}
		int cs = 0;
		if(s1 == 0) cs ++;
		if(s2 == 0) cs ++;
		if(s3 == 0) cs ++;
		if(cs == 2)
		{
			int p[N];
			for(int i = 1; i <= n; i ++)
			{
				p[i] = a[1][i];
			}
			sort(p + 1, p + n + 1, cmp);
			int pp = 0;
			for(int i = 1; i <= n / 2; i ++)
			{
				pp += a[1][i];
			}
			cout << pp << endl;
		}
		
		else{
			for(int i = 1; i <= 3; i ++)
			{
				for(int j = 1; j <= n; j ++)
				{
					if(a[i][j] == 0) continue;
					if(cnt[i] < n2)
					{
						dp[i][j] = dp[i][j - 1] + a[i][j];
						vis[i][j] ++;
						cnt[i] ++;
					}
					else
					{
						int id = -1, f = -1, minn = 2e9;
						for(int k = 1; k <= j - 1; k ++)
						{
							if(a[i][k] < minn)
							{
								minn = a[i][k];
								id = k;
								if(a[i][j] > a[i][k]) 
								{
									f = 1;
								}
							}
						}
						if(f == 1) 
						{
							int maxn = -1, maxbm;
							dp[i][j] = dp[i][j - 1] - minn + a[i][j];
							vis[i][j] ++;
							for(int k = 1; k <= 3; k ++)
							{
								if(k != i)
								{
									if(a[k][id] > maxn)
									{
										maxn = a[k][id];
										maxbm = k;
									}
								}
							}
							for(int k = id; k <= n; k ++)
							{
								dp[maxbm][id] += maxn;
							}
						}
						if(f == -1) dp[i][j] = dp[i][j - 1];
					}
				}
			}
			cout << max(max(dp[1][n], dp[2][n]), dp[3][n]);
			
		}
	}
	return 0;
}
