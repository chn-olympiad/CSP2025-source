#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(n==3)
	{
		int s=0,maxx=-10;
		for(int i=1;i<=3;i++)
		{
			s+=a[i];
			if(maxx<a[i]) maxx=a[i];
		}
		if(s>2*maxx)
		{
			cout<<"1";
			return 0;
		}
		cout<<s<<" "<<maxx;
	}
//	int maxx=-10;
//	for(int i=1;i<=n;i++)
//	{
//		if(maxx<a[i]) maxx=a[i];
//	}
	cout<<ans;
	return 0;
}
