#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005],maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3)
	{
		if(maxx*2<a[1]+a[2]+a[3]) 
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
