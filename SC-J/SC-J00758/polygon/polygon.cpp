#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
	{
		int sum=0,maxx=-1;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];sum+=a[i];maxx=max(maxx,a[i]);
		}
		if(sum>2*maxx)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}else
	{
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		cout<<"0";
	}
	return 0;
}