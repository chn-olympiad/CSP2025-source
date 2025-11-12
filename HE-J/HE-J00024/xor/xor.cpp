#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xpr.out","w",stdout);
	int n,k;
	int sm = 0;
	int a[230];
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i]; 
	for (int j = 1;j <= n;j++)
	{
		if (a[j] == k)
			sm++;
	}
	cout << sm; 
	return 0;
 } 
