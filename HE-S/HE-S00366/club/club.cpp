#include<bits/stdc++.h>
using namespace std;
int x[100002];
int y[100002];
int z[7];
int main;
{
	int a;
	cin>>a;
	int n,m=0;
	for(int i=1;i<=a;i++)
	{
		cin>>n;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<=3;j++)
		{
			y[i]=max(x[j],y[i]);
		}
		m+=y[i];
		for(int j=1;j<=3;j++)
		{
			if(y[i]==x[j])
			{
				z[j]++;
			}
		}
		for(int j=1;j<=3;j++)
		{
			if(z[j]<=n/2)
			{
				cout<<m;
			}
		}
	}
	return 0;
}
