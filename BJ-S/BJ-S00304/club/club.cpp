#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int a[100001];
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			int b,c;
			cin >> a[i] >> b >> c;
		}
		sort(a + 1,a + n + 1);
		int ans = 0;
		for(int i = n;i >= n/2;i++)
		{
			ans += a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
