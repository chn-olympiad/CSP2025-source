#include<bits/stdc++.h>
using namespace std;

int a[105];
int n, m, k, c, t, p;

int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n*m; i++) cin >> a[i];
    k = a[1];
	sort(a+1, a+1+n*m);
	for(int i=n*m; i>=1; i--)
	{
		if(a[i] == k)
		{
			c = n*m - i + 1;
			continue;
		}
	}
	t = c / (2*n);
	p = c % (2*n);
	if(p == 0)
	{
		cout << 2*t << ' ' << n;
	}else if(p <= n)
	{
		cout << 2*t+1 << ' ' << p;
	}else
	{
		cout << 2*t+2 << ' ' << 2*n-p+1;
	}
    return 0;
}
