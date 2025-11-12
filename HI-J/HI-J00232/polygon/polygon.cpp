#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s[5001][5001];
int ds[10005];
long long f[5005];
int g = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		s[i][i] = a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			s[i][j] = s[i][j-1]+a[j];
		}
	}
	for(int i = 1;i<= n;i++)
	{
		f[i] = f[i-1];
		for(int j = i+2;j <= n;j++)
		{
			int op = s[i][j]-2*a[j];
			if(op <= 0)
				continue;
			f[i]++;
			for(int k = i+1;k < j;k++)
			{
				for(int l = k;l < j;l++)
				{
					if(s[k][l] < op && j-i+1-(l-k) >= 3)
						f[i]++;
				}
			}
		}
	}
	cout << f[n];
	return 0;
}
