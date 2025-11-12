#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	int ans=b[1];
	sort(b+1,b+n*m+1,cmp); 
	int c=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
				a[i][j]=b[++c];	
		}
		else
		{
			for(int j=n;j>=1;j--)
				a[i][j]=b[++c];	
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==ans)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
