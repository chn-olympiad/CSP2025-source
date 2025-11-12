#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
using namespace std;
int a[1000];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	loop(i,n*m) cin >> a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=1;
	loop(i,n*m)
	{
		if (a[i]==t)
		{
			cout << x << " " << y << endl;
			return 0;
		}
		if (x&1)
		{
			if (++y==n+1) x++,y=n;
		} else {
			if (--y==0) x++,y=1;
		}
	}
	return 0;
}
