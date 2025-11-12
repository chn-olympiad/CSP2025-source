#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long cnt = 0;
	int a[5001] = {};
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n);
	for(int i = 1;i <= n;i++)
	{
		int j = i + 2,op = a[i] + a[i + 1];
		while(j <= n)
		{
			op += a[j];
			if(op > a[j] * 2)
			{
				for(int q = i + 1;q <= j;q++)
				{
					int x = q + 1,oq = a[q];
					while(x <= j)
					{
						if(op - oq > a[j] * 2)
						{
							cnt++;
						}
						else
						{
							break;
						}
						oq += a[x];
						x++;
					}
				}
				cnt++;
			}
			j++;
		}
	}
	cout << cnt % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}