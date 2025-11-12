#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum = 0;
	cin >> n;
	int a[n + 3],s[n + 3],mx[n + 3],maxn = 0;
	s[0] = 0;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] > maxn) maxn = a[i];
		s[i] = s[i - 1] + a[i];
		mx[i] = maxn;
	}
	for (int i = 3; i <= n; i ++)
		if (s[i] > mx[i] * 2)
		    sum ++;
	cout << sum << endl;
	return 0;
}
