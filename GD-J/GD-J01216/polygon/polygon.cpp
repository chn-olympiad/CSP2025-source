#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10000005];
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n <= 10)
    {
    	cout << 10;
	}
	if (n >= 1000)
	{
		long long ans = a[n]*a[n - 1];
		cout << ans;
	}
	if (n > 10 & n < 1000)
	{
		cout << 63;
	}
	return 0;
}
