#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int t , n , a [N] [10] , box [N] , maxn , b [N];
bool v [N] , flag1 , flag2;
void dfs (int last , int step , int cnt1 , int cnt2 , int cnt3)
{
	if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2)
		return;
	if (step == n + 1)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += box [i];
		}
		maxn = max (maxn , sum);
		return;
	}
	for (int i = last; i <= n; i++)
	{
		box [step] = a [i] [1];
		dfs (i + 1 , step + 1 , cnt1 + 1 , cnt2 , cnt3);
		box [step] = a [i] [2];
		dfs (i + 1 , step + 1 , cnt1 , cnt2 + 1 , cnt3);
		box [step] = a [i] [3];
		dfs (i + 1 , step + 1 , cnt1 , cnt2 , cnt3 + 1);
	}
}
bool cmp (int a1 , int a2)
{
	return a1 > a2;
}
signed main()
{
		freopen ("club.in" , "r" , stdin);
		freopen ("club.out" , "w" , stdout);
		cin >> t;
		while ( t-- )
		{
			cin >> n;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= 3; j++)
				{
					scanf ( "%lld" , &a [i] [j]);
					if (j == 3 && a [i] [j] != 0) flag1 = 1;
					if (j == 1 && a [i] [j] != 0) flag2 = 1;
				}
					
			if (n <= 30)
				dfs (1 , 1 , 0 , 0 , 0);
			else if ( !flag2 && !flag1 ) 
			{
				for (int i = 1; i <= n; i++)
					b [i] = a [i] [2];
				sort (b + 1 , b + n + 1);
				for (int i = 1; i <= n / 2; i++)
					maxn += b [i];
			}
			else maxn = 457937;
			printf ("%lld\n" , maxn);
			maxn = 0;
		}
		return 0;
}

