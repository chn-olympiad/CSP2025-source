#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	while(t --)
	{
		int ans = 0, w = 0, h = 0, k = 0;
		cin >> n;
		int a[n][3], f[n];
		for(int i = 0; i < n; i ++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][0] == 0) w ++;
			if(a[i][1] == 0) h ++;
			if(a[i][2] == 0) k ++;
			ans += max({a[i][0], a[i][1], a[i][2]});
		}
		if(w == n && h == n)
		{
			ans = 0;
			int l[n];
			for(int i = 0; i < n; i ++) l[i] = a[i][2];
			sort(l, l + n);
			for(int i = n - 1; i >= (n + 1) / 2; i --) ans += l[i];
		}
		else if(w == n && k == n)
		{
			ans = 0;
			int l[n];
			for(int i = 0; i < n; i ++) l[i] = a[i][1];
			sort(l, l + n);
			for(int i = n - 1; i >= (n + 1) / 2; i --) ans += l[i];
		}
		else if(h == n && k == n)
		{
			ans = 0;
			int l[n];
			for(int i = 0; i < n; i ++) l[i] = a[i][0];
			sort(l, l + n);
			for(int i = n - 1; i >= (n + 1) / 2; i --) ans += l[i];
		}
		if(n == 2) ans = max({max(a[0][0] + a[1][1], a[0][0] + a[1][2]), max(a[0][1] + a[1][0], a[0][1] + a[1][2]), max(a[0][2] + a[1][0], a[0][2] + a[1][1])});
		cout << ans << endl;
	}
	return 0;
}