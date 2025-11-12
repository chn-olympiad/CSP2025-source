#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105][105],t=100;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		if(i%2==1) 
		{
			for(int j=1;j<=n;j++) b[j][i]=t,t--; 
		}
		else
		{
			for(int j=n;j>=1;j--) b[j][i]=t,t--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==a[1])
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
