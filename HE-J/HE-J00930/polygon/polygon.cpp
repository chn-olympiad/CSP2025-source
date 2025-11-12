#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int m[n + 10];
	for(int i = 1;i <= n;i ++)
	{
		cin >> m[i];
	}
	int o = 0;
	sort(m + 1,m + n + 1);
	for(int i = 3;i <= n;i ++)
	{
		for(int j = 1;j <= n - i + 1;j ++)
		{
			int u = 0;
			for(int k = j;k <= j + i;k ++)
			{
				u += m[k];
			}
			if(u > m[j + i] * 2)o ++;
		}
	}
	cout << o;
	return 0;
}
