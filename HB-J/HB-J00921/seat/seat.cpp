#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[150];
int a2[15][15]={};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		
	}
	t=a[1];
	for(int i=1;i<n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}

	int d=1;
	
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			a2[i][j]=a[d];
			d++;
		
			
		}
		if(j==m)
		{
			break;
		}
		j++;
		for(int i=n;i>=1;i--)
		{
			a2[i][j]=a[d];
			d++;
			
		}
	}
	
for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
		{
			if(a2[i][j]==t)
			{
				cout<<j<<" "<<i;
			}
		}
		
	}
	return 0;
	
}
