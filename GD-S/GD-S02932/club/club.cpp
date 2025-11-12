#include <bits/stdc++.h>
using namespace std;

struct P
{
	int val, id;
};

struct W
{
	bool s;
	int w, j, k;
};

bool cmp(P& x, P& y)
{
	return x.val > y.val;
}

P arr[100000][3];
int dp[100000][3];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	
	cin >> t;
	
	while (t--)
	{
		int n, club[3] = {0, 0, 0}, ans = 0;
		
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> arr[i][j].val;
				
				arr[i][j].id = j;
			}
			
			sort(arr[i], arr[i] + 3, cmp);
		}
		
		for (int i = 0; i < n; ++i)
		{
			W w[3];
			int maxx = -1, maxp;
			
			for (int j = 0; j < 3; ++j)
			{
				if (club[arr[i][j].id] < n / 2)
				{
					w[j].s = false;
					w[j].j = j;
					w[j].w = arr[i][j].val;
				}
				
				else
				{
					int minn = 20001, minpos;
					
					for (int k = 0; k < i; ++k)
					{
						if (dp[k][arr[i][j].id] != 0)
						{
							int ww = dp[k][arr[i][j].id] - arr[k][j + 1].val;
							
							if (ww < minn)
							{
								minn = ww;
								minpos = k;
							}
						}
					}
					
					if (minn < arr[i][j].val)
					{
						w[j].s = true;
						w[j].j = j;
						w[j].k = minpos;
						w[j].w = arr[i][j].val - minn;
					}
				}
			}
			
			for (int j = 0; j < 3; ++j)
			{
				if (w[j].w > maxx)
				{
					maxx = w[j].w;
					maxp = j;
				}
			}
			
			if (w[maxp].s)
			{
				int j = w[maxp].j, minpos = w[maxp].k;
				
				dp[minpos][arr[i][j].id] = 0;
				dp[minpos][arr[minpos][j + 1].id] = arr[minpos][j + 1].val;
				dp[i][arr[i][j].id] = arr[i][j].val;
			}
			
			else
			{
				int j = w[maxp].j;
				
				dp[i][arr[i][j].id] = arr[i][j].val;
				++club[arr[i][j].id];
			}
			
			ans += maxx;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
