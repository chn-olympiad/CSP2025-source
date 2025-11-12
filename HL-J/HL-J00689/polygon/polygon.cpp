#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		ans=0;
	}
	else if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*maxx)
		{
			ans=1;
		}
	}
	else
	{
		return 0;
	}
	cout<<ans;
	return 0;
}
