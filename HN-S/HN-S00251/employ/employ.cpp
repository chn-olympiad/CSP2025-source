#include <bits/stdc++.h>
using namespace std;

long long n;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long ans = 1;
	while(n > 0)
	{
		ans *= n;
		n--;
	}
	cout << ans;
	return 0;
}
