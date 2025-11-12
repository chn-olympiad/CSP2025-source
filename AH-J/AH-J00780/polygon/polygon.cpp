#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long i,n,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			s++;
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>(a[3]*2))
			cout<<1;
		else
			cout<<0;
		return 0;
	}
}
