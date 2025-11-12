#include<bits/stdc++.h>
using namespace std;
int n,m;
bool ff(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m],b[n][m];
	cin>>a[0];
	int x=a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m,ff);
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
			{
				b[j][i]=a[i*n+j];
			}
		}
		else
		{
			for(int j=m-1;j>=0;j--)
			{
				b[j][i]=a[i*n+m-j-1];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(b[i][j]==x)
			{
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
}
