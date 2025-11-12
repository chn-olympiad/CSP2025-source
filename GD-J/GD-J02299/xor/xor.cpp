#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],A[500005],sum,f,cnt,lst = 1,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		sum ^= a[i];
		x = sum;
		for (int j = lst;j < i && x != m;j++)
		{
			x ^= a[j];
		}
		if (x == m)
		{
			cnt++;
			sum = 0;
			lst = i + 1; 
		}
	}
	cout << cnt; 
	return 0;
} 

