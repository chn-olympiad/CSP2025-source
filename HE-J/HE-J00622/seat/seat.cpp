#include<bits/stdc++.h>
using namespace std;
char a[14][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int m,n,s;
cin>>m>>n>>s;
for(int i=1;i<=m;i++)
{
	for(int j=1;j<=n;j++)
	{
	cin>>a[i][j];
	}
}
cout<<endl;
for(int i=1;i<=m-1;i++)
{
	for(int j=1;j<=n-1;j++)
	{
		cout<<a[i][j]<<" ";
	}
}
cout<<endl;
	return 0;
}
