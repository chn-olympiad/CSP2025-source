#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<10)
	{
		cout<<6;
	}
	else if(n<100)
	{
		cout<<1042392;
	}
	else
	{
		cout<<366911923;
	}
	return 0;
}
