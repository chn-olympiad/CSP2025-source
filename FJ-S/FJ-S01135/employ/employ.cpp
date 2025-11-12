#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n = 0, m = 0;
	scnaf("%d%d", &n, &m);
	string s;
	s.resize(n);
	scanf("%c", &s[0]);
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int cnt = 0;
	for (char i : s)
		if (i == '1')
			++cnt;
	if (m > cnt)
		printf("0");
	else
	{
		long long ans;
		for (int i = 2; i <= n; ++i)
			ans = (ans * (long long)(i)) % 998244353;
		printf("%d", ans);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
