#include<bits/stdc++.h>
using namespace std;
int x,y,a[105],n,m,g,k=1;
int t[15][15];
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
		cin>>a[i];
	}g=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int p=1;p<=m/2;p++)
    {
		for(int i=1;i<=n;i++) t[i][p*2-1]=a[k++];
		for(int i=n;i>=1;i--) t[i][p*2]=a[k++];
	}
	if(m%2!=0)
	{
		for(int i=1;i<=n;i++) t[i][m]=a[k++];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(t[i][j]==g)
	{
		x=i;y=j;
		break;
	}
	cout<<y<<" "<<x;
    return 0;
}
