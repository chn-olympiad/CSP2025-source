#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a1=0,a0=0,lx1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		a0++;
		else
		a1++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			if(a[i+1]==1)
			{
				lx1++;
				i++;
			}
		}
	}	
	if(k==0)
	cout<<a0+lx1;
	else
	cout<<a1;
	
	return 0;
}
