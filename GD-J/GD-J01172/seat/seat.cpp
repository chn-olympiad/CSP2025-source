#include<bits/stdc++.h>
using namespace std;
bool cmp(int d,int e)
{
	return d>e;
}
int a[15][15],c[225];
int n,m,w;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>c[i];
	w=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++) 
			{
				a[i][j]=c[(i-1)*n+j];
				if(a[i][j]==w) cout<<i<<' '<<j;
			}
		}
		else
		{
			for(int j=n;j>=1;j--) 
			{
				a[i][j]=c[(i-1)*n+n-j+1];
				if(a[i][j]==w) cout<<i<<' '<<j;
			}
		}
	}
	return 0;
 } 
