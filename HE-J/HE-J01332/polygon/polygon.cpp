#include<bits/stdc++.h>
using namespace std;
int StickMax(int len[],int n)
{
	int max=len[0];
	for(int i=0;i<n;i++)
	{
		if(len[i]>max) max=len[i];
	}
	return max;
}
int count(int n,int len[],int m,int max)
{
	if(m-1!=2)
	{
		return count(n,len,m-1,max);
	}
	else
	{
		int sum=0;
		for(int i=1;i<=n-m+1;i++)
		{
			for(int j=i+1;j<=n-m+2;j++)
			{
				for(int k=j+1;k<=n-m+3;k++)
				{
					if(i+j+k>max)
						sum++;
				}
			}
		}
		return sum;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	int a[n+1];
	int max=StickMax(a,n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int m=3;m<=n;m++)
	{
		sum+=count(n,a,m,max);
	}
	cout<<908%244%353%sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
