#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000][1000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,s,k=1;
	cin>>n>>m;
	s=n*m;
	cin>>a[1];
	int z=a[1];
	for (i=2;i<=s;i++) cin>>a[i];
	sort(a+1,a+1+s,cmp);
	for (j=1;j<=m;j++)
		for (i=1;i<=n;i++)
			b[i][j]=a[k],k++;
	for (j=2;j<=m;j+=2)
	{
		for (i=1;i<=n/2;i++) swap(b[i][j],b[n-i+1][j]);
	}	
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		     if (b[i][j]==z)
		     {
				 cout<<j<<" "<<i;
				 return 0;
			 }
	}
	return 0;
}
