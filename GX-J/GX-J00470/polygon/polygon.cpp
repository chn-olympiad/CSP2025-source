#include <bits/stdc++.h>
using namespace std;
int n;
int m=0;
int a[5001];
int js(int l,int r)
{
	int o=0;
	for(int i=l;i<=r;i++)
	{
		o+=a[i];
	}
	return o;
}
int marx=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>marx)
		{
			marx=a[i];
		}
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			for(int k=j;k<=n;k++)
			{
				if(j!=1&&j!=i)
				{
					if(js(1,j-1)+js(j+1,i)+a[k]==2*marx)
					{
						m++;
					}
					k+=1;
				}
				else if(j==i)
				{
					if(js(1,j-1)+a[k]==2*marx)
					{
						m++;
					}
					k+=1;
				}
				else if(j==1)
				{
					if(js(j+1,i)+a[k]==2*marx)
					{
						m++;
					}
				}
			}
		}
	}
	cout<<m<<endl;
	return 0;
}
