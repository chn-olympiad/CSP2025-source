#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i=1,j=1;
	cin>>n>>m;
	int map[n+1][m+1],a[n*m],ji=n*m-1,ans;
	for(int x=0;x<n*m;x++)
	{
		cin>>a[x];
		if(x==0) ans=a[x];
	}
	sort(a+0,a+n*m);
	for(i;i<=n;)
	{
		for(j;j<=m;)
		{
			if(ans==a[ji])
			{
				cout<<j<<" "<<i;
				return 0;
			}
			ji--;
			if(i==n&&j%2==1)
			{
				j++;
			}
			else if(i==1&&j%2==0)
			{
				j++;
			}
			else if(j%2==1)
			{
				i++;
			}
			else if(j%2==0)
			{
				i--;
			}
		}
	}
	return 0;
} 
