#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
int b[250];
int renn;
int tot=0;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	renn=b[1];
	sort(b+1,b+249,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[++tot];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[++tot];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==renn)
			{
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
