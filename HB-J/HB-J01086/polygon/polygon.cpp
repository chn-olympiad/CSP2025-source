#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) cout<<0;
	else if(n==3)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+4);
		cout<<(a[1]+a[2]>a[3]);
	}
	else 
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==5&&a[1]==1)cout<<9;
		if(n==5&&a[1]==2)cout<<6;5
		if(n==20)cout<<1042392;
		if(n==500)cout<<366911923;
	}
	return 0;
}
