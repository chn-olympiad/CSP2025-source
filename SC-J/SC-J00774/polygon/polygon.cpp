#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxx=-1,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(sum>2*maxx)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}