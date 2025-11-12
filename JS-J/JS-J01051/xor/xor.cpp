#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[500001];
int ans;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int ans0 = 0, ans1 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) ans0++;
		if (a[i] == 1) ans1++;
	}
	if (k == 0) {
		cout << ans0;
		return 0;
	}
	if (k == 1) {
		cout << ans1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == k) ans++;
	}
	cout << ans;
	return 0;
}
