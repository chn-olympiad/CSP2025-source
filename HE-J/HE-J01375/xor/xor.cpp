#include <bits/stdc++.h>
using namespace std;
int n,k,f,f0,s,j,g;
const int N=1e6;
int a[N];
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
			f=1;
		}
		if(a[i]!=0&&a[i]!=1)
		{
			f0=1;
		}
	}
	if(k==0&&a[1]==1&&n>=1&&n<=2) cout<<0;
	else if(k==0&&f==0)
	{
		for(int l1=1;l1<=n;l1++)
		{
			for(int r1=1;r1<=n;r1++)
			{
				for(int l2=r1+1;l2<=n;l2++)
				{
					for(int r2=l2;r2<=n;r2++)
					{
						if((r2-l2+1)%2==(r1-l1+1)%2)
						{
							s++;
						}
					}
				}
			}
		}
		cout<<s;
	}
	else 
	{
		for(int l1=1;l1<=n;l1++)
		{
			for(int r1=1;r1<=n;r1++)
			{
				for(int l2=r1+1;l2<=n;l2++)
				{
					for(int r2=l2;r2<=n;r2++)
					{
						j=a[l1];
						g=a[l2];
						for(int i=l2+1;i<=r2;i++)
						{
							j=j^a[i];
						}
						for(int d=l1+1;d<=r1;d++)
						{
							g=g^a[d];	
						}
						if(j==k&&g==k) s++;
					}
				}
			}
		}
		cout<<s;
	}
	return 0;
}
