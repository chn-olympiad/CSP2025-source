#include <bits/stdc++.h>
using namespace std;
int n ,a[5005], ans;
const int mod = 998244353;
bool check(int sum, int maxx)
{
	return sum > 2 * maxx;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++)
	    cin >> a[i];
	for(int i = 7;i < (1 << n);i ++)
	{
		int num = 0, mx = 0, cnt = 0;
		for(int j = 0;j < n;j ++)
			if(i & (1 << j))
			{
				num += a[j + 1];
				mx = max(a[j + 1], mx);
				cnt ++;
			}
		if(cnt < 3)
		    continue;
		if(check(num, mx))
			ans = (ans % mod + 1) % mod;
	}
	cout << ans;
	return 0;
}