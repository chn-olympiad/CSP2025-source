#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[105];
	int sum=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=max(sum,a[i]);
		ans+=a[i];
	}
	sum*=2;
	if (ans>sum)
		cout<<1;
	else
		cout<<0;
	return 0;
}
