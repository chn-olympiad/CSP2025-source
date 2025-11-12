#include <iostream>
using namespace std;

int n,k,l,a[500100],b[500100];
signed masin()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i>1) b[i]=a[i]^b[i-1];
		if (a[i]!=1) l=1;
	}
	if(!l&&k!=1)
	{
		cout<<0;
		return 0;
	}
	else if(!l&&k==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(j-i>0)
				
		}
	}
	
	return 0;
}
