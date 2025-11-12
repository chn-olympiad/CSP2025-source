#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[0]+a[1]+a[2]>a[2]*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
