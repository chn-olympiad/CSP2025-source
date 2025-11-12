#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int s[m+5][n+5];
	int k=1;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			s[i][j]=k;
			k++;
		}
		k+=n;
	}
	k=n+1;
	for(int i=2;i<=m;i+=2)
	{
		for(int j=n;j>=1;j--)
		{
			s[i][j]=k;
			k++;
		}
		k+=n;
	}
	
	int z=n*m;
	for(int i=1;i<=z;i++)
	{
		cin>>a[i];
	}
	int fen=a[1];
	sort(a+1,a+z+1,cmd);
	int p;
	for(int i=1;i<=z;i++)
	{
		if(a[i]==fen)
		{
			p=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[j][i]==p)
			{
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
