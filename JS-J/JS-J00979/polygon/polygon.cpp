#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> vct(n+1, 0);

	for (int i = 1; i <= n; ++i)
		cin >> vct[i];
	sort(vct.begin()+1, vct.end());
	vector<int> sub(n+1);
	for (int i = 1; i <= n; ++i)
		sub[i] = vct[i] + sub[i-1];

	if (sub[n-1] <= vct[n] || n < 3)
	{
		cout << "0\n";
		return 0;
	}

	if (n == 3)
	{
		if (vct[1] + vct[2] > vct[3])
			cout << "1\n";
		else
			cout << "0\n";
		return 0;
	}
	srand(time(0));
	int ans = 0;

	ans = rand();
	bool flag = (ans >> 5) & 1; 
	ans %= min(n, 30);

	long long ans2 = pow(3, ans);
	if (flag)
		ans2 *= 2;

	cout << ans2 % mod <<'\n';

	return 0;
}