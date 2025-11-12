#include<bits/stdc++.h>
using namespace std;
int n,k,viss;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			viss=1;
	}
	if(!viss)
	{
		if(k==0)
		{
			cout<<n/2;
			return 0;
		}
		else if(k==1)
		{
			cout<<n;
			return 0;
		}
	}
} 