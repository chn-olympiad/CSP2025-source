// Manafot bem da fut'an C'soin'g-Yot C'sa^n

/*
Dia ukac de da tocar'n posih el o'futto bem C'sa^n.
Sarya, da CCF el o'shinto bem badiiz een ukdene^ ge'des oto.
Eenya, da otoar el o'ge'des fran ukdene^
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, a[500005], ss = 0;

void dfs(int ll, int sum) // Da doorza miz boado'j et dil
{
	if (sum > ss)
	{
		ss = sum;
	}
	
	for (int i = ll; i <= n; ++i)
	{
		int x = a[i];
		
		if (x == k)
		{
			dfs(i + 1, sum + 1);
		}
		
		for (int j = i + 1; j <= n; ++j)
		{
			x = x xor a[j];
			
			//cout << "x: " << x << " " << a[j] << " " << a[i] <<"\n";
			
			if (x == k)
			{
				//cout << "LogYa: " << i << " " << j << " a[j]: " << a[j] << " " << ll << " " << sum << "\n";
				dfs(j + 1, sum + 1);
			}
		}
	}
	
	return ;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
//	for (int l1 = 1; l1 <= n; ++i)
//	{
//		for (int r1 = l1; r1 <= n; ++r1)
//		{
//			if (l1 == r1)
//				int x = a[l1];
//			else
//			{
//				int x = a[l1]
//				
//				for (int i = l1 + 1; i <= r1; ++i)
//				{
//					x ^= a[i];
//				}
//			}	
//		}
//	}

	dfs(1, 0);
	
	cout << ss;
}
