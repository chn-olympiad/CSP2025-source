#include <bits/stdc++.h>
#define long long int;
using namespace std;
int n,k;
int a[50000];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=false;
		}
	}
	if(f==true)
	{
		if(k==1)
		{
			cout<<n;
		}
		else if(k==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
} 
