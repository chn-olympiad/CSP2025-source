#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[15][15],c[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h=0,l;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	h++;
	  	cin>>a[i][j];
	  	c[h]=a[i][j];
	  }
	l=a[1][1];
	sort(c+1,c+h+1);
	reverse(c+1,c+h+1);
	h=0;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	h++;
	  	a[i][j]=c[h];
	  }
	for(int i=1;i<=m;i=i+2)
	  for(int j=1;j<=n;j++)
	  {
	  	b[i][j]=a[i][j];
	  }
	for(int i=2;i<=m;i=i+2)
	{
		h=0;
		for(int j=n;j>=1;j--)
	    {
	  	  h++;
	  	  b[i][j]=a[i][h];
	    }
	}
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	if(b[i][j]==l)
	  		cout<<i<<" "<<j;
	  }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
