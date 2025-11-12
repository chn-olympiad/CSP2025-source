#include <iostream>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll a[N],ps[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	ll k;
	cin >> n >> k;
	bool flaga = 1, flagb = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ps[i] = ps[i-1]^a[i];
		if (a[i] != 1) flaga = 0;
		if (a[i] > 1) flagb = 0;
	}
	if (flaga && k == 0)
	{
		cout << n/2;
		return 0;
	}
	if (flagb)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (a[i] == 1) cnt++;
		if (k == 0) cout << cnt/2;
		else cout << cnt;
		return 0;
	}
	int i = 1;
	int ans = 0;
	ll now = 0;
	while (i <= n)
	{
		now ^= a[i];
		if (now == k)
		{
			ans++;
			now = 0;
		}
		++i;
	}
	cout << ans;
	return 0;
}
