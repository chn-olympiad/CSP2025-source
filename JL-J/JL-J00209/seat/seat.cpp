#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,ans = 1;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++)
		cin >> a[i];
	s = a[1];
	for(long long i = 1 ; i <= n * m ; i++)
		if(s < a[i])
			ans++;
	cout << ((ans + n - 1) / n) << " ";
	if(ans % (2 * n) <= n)
		cout << ans % (2 * n);
	else
		cout << n - (ans % (2 * n) - n) + 1;
	return 0;
}
