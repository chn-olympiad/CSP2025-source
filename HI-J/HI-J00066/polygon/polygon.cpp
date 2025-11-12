#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans;
	ans= 0;
	cin>>n;
	if(n < 3)
	{
		cout << ans;
		return 0;
	}
	int a[n];
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
	ans = n;
	}
	cout << ans;
	return 0;
}
