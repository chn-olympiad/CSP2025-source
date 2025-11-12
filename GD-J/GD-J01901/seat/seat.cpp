#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int k=n*m;
	for (int i = 1;i <= k;i++) cin >> a[i];
	int num = a[1];
	sort(a+1,a+k+1);
	int x;
	for (int i = 1;i <= k;i++)
	{
		if (a[i]==num)
		{
			x = k - i + 1;
			break;
		}
	}
	int y = (x/n);
	if (x % n!=0) y++;
	cout << y << " " << x;
	int ans;
	if (y%2==1)
	{
		ans = x % (2*n);
		cout << y << " " << ans;
	}
	else
	{
		ans = n-x%(n+1);
		cout << y << " " << ans;
	}
	return 0;
}
