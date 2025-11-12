#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],t,sum,s[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	int sum=n*m+1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
			for(int j=1;j<=m;j++)
				s[i][j]=a[--sum];		
		else
			for(int j=m;j>=1;j--)
				s[i][j]=a[--sum];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==t)
			{
				cout<<i<<" "<<j;
				return 0;
			}	
	return 0;
}
