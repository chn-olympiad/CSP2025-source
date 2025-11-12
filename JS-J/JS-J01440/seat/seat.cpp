#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int n, m, cnt;
int c, r, d = 1;
int a[105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mt19937 rng((unsigned long long)(new char));
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	for(int i = 2;i <= n*m;i++)
		if(a[i] > a[1])
			cnt++;
	c = 1, r = 1, d = 1;
	while(cnt--)
	{
		r += d;
		if(r > n)
		{
			d *= -1;
			r = n;
			c++;
		}
		if(r < 1)
		{
			d *= -1;
			r = 1;
			c++;
		}
	}
	cout << c << " " <<  r << endl;
	
	return 0;
}
