#include<bits/stdc++.h>
using namespace std;
int n,m;
int t;
int v[20][20];
struct node
{
	int x,y;
}a[120];
int cmp(node a1,node b1)
{
	return a1.x>b1.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].y==1)
		{
			t=i;
			break;
		}
	}
	// cout<<t<<'\n';
	int k=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			v[j][i]=k;
			k++;
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 	{
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	for(int i=2;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			v[j][i]=v[j][i]+n-j+1-j;
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 	{
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(v[i][j]==t)
			{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}