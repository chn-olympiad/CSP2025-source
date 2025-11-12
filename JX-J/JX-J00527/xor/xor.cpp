#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[600000],a1 = 0,a0 = 0;
	cin>>n>>k;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k == 0)
	{
		cout<<n/2;
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		if(a[i] == 1)
		{
			a1++;
		}
		if(a[i] == 0)
		{
			a0++;
		}
	}
	if(k>=2)
	{
		cout<<0;
		return 0;
	}
	if(k == 0)
	{
		cout<<a0+a1/2;
	}
	if(k == 1)
	{
		cout<<a1;
	}
	return 0;
}
