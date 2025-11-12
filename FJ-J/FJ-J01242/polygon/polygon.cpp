#include<bits/stdc++.h>
using namespace std;
int n,a[5003],s[5003],mx[5003][5003],d[5003];
bool pd(int x,int y,int z)//ijk
{
	int sum=s[y]-s[z-1]+a[x];
	int mxa=max(mx[z][y],a[x]);
	if(sum>mxa*2)
	return true;
	return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		mx[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			mx[i][j]=max(a[j],mx[i][j-1]);
		}
	}
	for(int i=3;i<=n;i++)
	{
		d[i]=d[i-1];
		for(int j=i-1;j>=2;j--)
		{
			for(int k=j-1;k>=1;k--)
			{
				if(mx[k][i]*2<s[i]-s[k-1])
				{
					d[i]++;
				}
			}
		
		}
		d[i]%=998224353;
	}
	cout<<d[n];
	return 0;
}
/*
5
2 2 3 8 10
*/
