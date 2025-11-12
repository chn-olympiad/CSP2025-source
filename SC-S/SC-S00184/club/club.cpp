#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a [N] , b [N] , c [N] , vis [N] , maxn , n;
void dfs (int step , int cnta , int cntb , int cntc)
{
	if (step >= n)
	{
		if (cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2)
		{
			int sum = 0;
			for (int i = 1;i <= n;i++)
			{
				if (vis [i] == 1)
				{
					sum += a [i];
				}
				else if (vis [i] == 2)
				{
					sum += b [i];
				}
				else
				{
					sum += c [i];
				}
			}
			maxn = max (maxn , sum);
		}
		return ;
	}
	if (cnta > n / 2 || cntb > n / 2 || cntc > n / 2)
	{
		return ;
	}
	dfs (step + 1 , cnta + 1 , cntb , cntc);
	vis [step] = 1;
	dfs (step + 1 , cnta , cntb + 1 , cntc);
	vis [step] = 2;
	dfs (step + 1 , cnta , cntb , cntc + 1);
	vis [step] = 3;
}

int main ()
{
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while (t --)
	{
		maxn = 0;
		memset (vis , 0 , sizeof (vis));
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a [i] >> b [i] >> c [i];
		}
		dfs (1 , 0 , 0 , 0);
		cout << maxn << endl;
	}
	return 0;
}
