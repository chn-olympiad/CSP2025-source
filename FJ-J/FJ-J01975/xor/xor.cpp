#include<bits/stdc++.h>
using namespace std;
int n,k,a[266],ax,bx,sum,b[266],x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			ax++;
			if(a[i]!=0)
			{
				bx++;
			}
		}
	}
	if(ax==0)
	{
		cout<<n/2;
		return 0;
	}
	if(bx==0)
	{
		if(k==1)
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==a[i-1])
				{
					sum++;
					b[x] = i;
					i++;
				}
			}
			for(int i=1;b[i]!=0;i++)
			{
				if(a[b[i]]==1)
				{
					sum++;
				}
			}
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==a[i-1])
				{
					sum++;
					i++;
				}
			}
		}
		cout<<sum;
		return 0;
	} 
	return 0;
}
