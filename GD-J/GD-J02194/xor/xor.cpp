#include<iostream>
#include<cstdio>
using namespace std;
int a[500000],n,k;
bool f[500000];
int xor8(int x,int y)
{
	if(x==y)
	{
		return a[x];
	}
	else
	{
		return a[x] xor xor8(x+1,y);	
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int p=0;
	while(p<n)
	{
		for(int i=0;i<n;i++)
		{
			int j=i+p;
			if(j>=n)
			{
				break;
			}
			if(xor8(i,j)==k)
			{
				bool flag=0;
				for(int k=i;k<=j;k++)
				{
					if(f[k]==1)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					break;
				}
				for(int k=i;k<=j;k++)
				{
					f[k]=1;
				}
				cnt++;
			}
		}
		p++;
	}
	cout<<cnt;
	return 0;
}
