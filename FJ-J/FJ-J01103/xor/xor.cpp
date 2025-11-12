#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[500050],maxn=INT_MIN,szonghe;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			szonghe++;
		}
		else if(a[i]!=a[i+1])
		{
			maxn=max(maxn,szonghe);
			szonghe=1;
		}
	}
	if(maxn==0)
	{
		cout<<1;
	}
	else
	{
		cout<<max(maxn,szonghe);
	}
	return 0; 
} 
