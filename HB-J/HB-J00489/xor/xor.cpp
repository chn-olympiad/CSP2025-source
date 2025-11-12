#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[500005];
int n,m,s=1,maxn=0,num=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
		if(a[i]!=1)s=0;
		maxn=max(a[i],maxn);
	}
	if(maxn==1&&s==1)
	{
		if(m==0)cout<<n/2;
		else cout<<n;
	}
	else if(maxn==1&&s==0)
	{
		if(m==0)
		{
			num=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)num++;
				else
				{
					if(a[i-1]==1)
					{
						num++;
						a[i]=0;
					}
				}
			}
			cout<<num;
		}
		else cout<<num;
	}
	return 0;
}
