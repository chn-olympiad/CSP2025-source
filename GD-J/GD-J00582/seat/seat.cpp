#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,g[101],s[11][11];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>g[i];
	int r=g[1],cnt=n*m;
	sort(g+1,g+n*m+1);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				s[i][j]=g[cnt];
				cnt--;
			}
		}
		else 
		{
			for(int j=m;j>=1;j--)
			{
				s[i][j]=g[cnt];
				cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==r)	
			{
				cout<<i<<" "<<j;
				return 0;
			}
} 
