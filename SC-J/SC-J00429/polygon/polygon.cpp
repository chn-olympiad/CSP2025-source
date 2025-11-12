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
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
	}
	if(ans>(2*a[n]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
