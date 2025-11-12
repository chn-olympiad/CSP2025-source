#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, a[5005], sum = 0, ans = 0, num = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a+1, a+n+1);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i+1; j <= n; j ++)
		{
			for (int k = j+1; k <= n; k ++)
			{
				if (a[i]+a[j] > a[k])	sum ++;
				else break;
			} 
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
				{
					if (a[i]+a[j]+a[k] > a[o]) sum ++;
					else break;
				}
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
					for (int y = o+1; y <= n; y ++)
					{
						if (a[i]+a[j]+a[k]+a[o] > a[y]) sum ++;
						else break;
					}
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
					for (int y = o+1; y <= n; y ++)
						for (int p = y+1; p <= n; p ++)
						{
							if (a[i]+a[j]+a[k]+a[o]+a[y] > a[p]) sum ++;
							else break;
						}
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
					for (int y = o+1; y <= n; y ++)
						for (int p = y+1; p <= n; p ++)
							for (int m = p+1; m <= n; m ++)
							{
								if (a[i]+a[j]+a[k]+a[o]+a[y]+a[p] > a[m]) sum ++;
								else break;
							}
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
					for (int y = o+1; y <= n; y ++)
						for (int p = y+1; p <= n; p ++)
							for (int m = p+1; m <= n; m ++)
								for (int u = m+1; u <= n; u ++)
								{
									if (a[i]+a[j]+a[k]+a[o]+a[y]+a[p]+a[m] > a[u]) sum ++;
									else break;
								} 
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
					for (int y = o+1; y <= n; y ++)
						for (int p = y+1; p <= n; p ++)
							for (int m = p+1; m <= n; m ++)
								for (int u = m+1; u <= n; u ++)
									for (int q = u+1; q <= n; q ++)
									{
										if (a[i]+a[j]+a[k]+a[o]+a[y]+a[p]+a[m]+a[u] > a[q]) sum ++;
										else break;
									}
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				for (int o = k+1; o <= n; o ++)
					for (int y = o+1; y <= n; y ++)
						for (int p = y+1; p <= n; p ++)
							for (int m = p+1; m <= n; m ++)
								for (int u = m+1; u <= n; u ++)
									for (int q = u+1; q <= n; q ++)
										for (int w = q+1; w <= n; w ++)
										{
											if (a[i]+a[j]+a[k]+a[o]+a[y]+a[p]+a[m]+a[u]+a[q] > a[w]) sum ++;
											else break;
										} 				
	cout << sum;
	return 0;
}
