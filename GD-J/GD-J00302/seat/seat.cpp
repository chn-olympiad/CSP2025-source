#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[105],b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nn=1,mm=1;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int xiaoming=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xiaoming)
			xiaoming=i;	
	}
	cout
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;i++)
		{
			if(b[i][j]==xiaoming)
				cout<<i<<j;
		}
	}
	return 0;
}
