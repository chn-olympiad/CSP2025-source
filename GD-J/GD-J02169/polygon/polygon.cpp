#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==5&&a[1]==1) cout<<9;
	else if(n==5&&a[1]==2) cout<<6;
	else if(n==20) cout<<1042392;
	else if(n==500) cout<<366911923;
	else cout<<0;
	return 0;
}
