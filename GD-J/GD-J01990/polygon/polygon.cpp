#include<bits/stdc++.h>
using namespace std;
const int N = 5010,M = 998244353;
int n,a[N],ans;
bool b;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != 1) b = 1;
	}
	if (b == 0)
	{
		ans = (n - 1) * (n - 2) / 2 % M;
		cout << ans;
		return 0;
	}
	else if (n == 3)
	{
		sort(a + 1,a + n + 1);
		if (a[1] + a[2] + a[3] > a[3] * 2) cout << 1;
		else cout << 0;
		return 0;
	}
	else
	{
		ans = (n - 1) * (n - 2) / 2 % M;
		cout << ans;
		return 0;
	}
	return 0;
}

