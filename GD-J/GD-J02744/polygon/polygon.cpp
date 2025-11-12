#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, MOD = 998244353;
int n;
int a[N];

signed main()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	} 
	if (n <= 2)
	{
		cout << 0;
	}
	else if (n == 3)
	{
		if (max (a[1], max (a[2], a[3])) * 2 > a[1] + a[2] + a[3])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		int b[n + 5][n + 5];
		memset (b, 0, sizeof b);
		int cur = 2;
		b[1][1] = 1;
		for (int i = 2; i <= n - 2; i++)
		{
			b[i][1] = 1;
			b[1][i] = b[1][i - 1] + cur;
			cur++;
		}
		for (int i = 2; i <= n - 2; i++)
		{
			for (int j = 2; j <= n - i - 1; j++)
			{
				b[i][j] = b[i - 1][j] + b[i][j - 1];
			}
		}
		int sum = 0;
		for (int i = 1; i <= n - 1; i++)
		{
			for (int j = 1; j <= n - i - 1; j++)
			{
				sum += b[i][j];
				sum %= MOD;
			}
		}
		cout << sum % MOD << '\n';
	}
	
	return 0;
}
//bu zheng le zheng bu dong le
//ren sheng lu man man
//gan jue da wan zhe ci jiu yao tui yi le 
//mei jiu le
//xue le zhe me jiu
//xian zai lian pu ji zu dou bu neng AK
//wo hai shi tai fei wu le
//you mei you ren dong wo a
//ci ke wo hao jue wang
//hai you 5 min
//zai jian le OI
//xi wang ni xi huan zhe 6 nian lai shu yu ni de xi fen
//hope see you again
//...... 
