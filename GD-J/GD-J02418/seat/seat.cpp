#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n*m;i++)
		cin >> a[i];
	int res = a[1];
	sort(a,a+n*m+1);
	for (int i = 1;i<=n*m;i++)
	{
		if(a[i] == res)
		{
			ans = i;
			break;
		}
	}
	ans = n*m - ans + 1;
	double s = ans*1.0 / n;
	int c = ceil(s),r1 = ans % n,r;
	if (c % 2 == 1)
	{
		if (r1 == 0) r = n;
		else r = r1;
	}
	else{
		if (r1 == 0) r =1; 
		else r = n - r1+1;
	}
	cout << c << " " << r;
    return 0;
}

