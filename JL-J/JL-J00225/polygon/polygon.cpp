#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5], cnt = 0;
	cin >> n;
	for(int i = 1; i <= 3; i++)
	{
		cin >> a[i];
		cnt += a[i];
	}
	if(n < 3)
		cout << "0";
	int maxN;
	for(int i = 1; i <= 3; i++)
	{
		maxN = a[i];
		for(int j = 1; j <= 3; j++)
			maxN = max(maxN, a[j]);
	}
	if(n == 3)
	{
		if(cnt == maxN * 2)
			cout << "1";
		else cout << "0";
	}
	return 0;
}
