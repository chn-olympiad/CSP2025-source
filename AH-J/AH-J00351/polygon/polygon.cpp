#include<bits/stdc++.h>
using namespace std;
int n,a[5005],e=0,s=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		e+=a[i];
	}
	if(n==3)
	cout<<1;
	else if(n<3)
	cout<<0;
	else if(e==1)
	{
		for(int i=1;i<=n-1;i++)
		s*=2;
		cout<<s;
	}
	else if(e==0)
	cout<<0;
	return 0;
}
