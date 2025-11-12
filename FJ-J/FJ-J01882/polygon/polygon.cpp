#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5002];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	if(n<3)
	{
		cout<<0;
	} 
	if(n==3)
	{
		if(a[1]+a[2]>2*a[3]||a[1]+a[3]>2*a[2]||a[2]+a[3]>2*a[1])
		{
			cout<<1;
		}
	}
	return 0;
}
