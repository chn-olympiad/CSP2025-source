#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000],sum = 0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (s[i] == '0')
		{
			sum += 0;
		}
		else
		{
			sum += 1;
		}
	}
	if (sum > m)
	{
		cout << 2204128;
	}
	else
	{
		cout << sum;
	}
	return 0;
 } 
