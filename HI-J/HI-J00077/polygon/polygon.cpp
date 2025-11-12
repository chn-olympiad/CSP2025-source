#include <bits/stdc++.h>
using namespace std;
int a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
