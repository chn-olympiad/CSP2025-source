#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[6000];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
		
	}
	int ans = 0;
	sort(a+1,a+n+1);
	ans = a[n/2+1]+a[n]+a[1];
	if (ans<10)
	{
		ans = ans+0;
	}
    cout <<ans;
    return 0;
}
