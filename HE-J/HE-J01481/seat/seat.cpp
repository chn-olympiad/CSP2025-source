#include<bits/stdc++.h>
using namespace std;
int a[110],c[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,x,s;
	cin>>n>>m;
	s=n*m;
	for(i=1;i<=s;i++)
	    cin>>a[i];
	x=a[1];
	sort(a+1,a+1+s);
	for(i=1;i<=m;i++)
	{
	    if(i%2)
	    for(j=1;j<=n;j++)
	    {
	        c[i][j]=a[s];
	        s--;
	    }
	    else
	    for(j=n;j>=1;j--)
	    {
	    	c[i][j]=a[s];
	    	s--;
		}
	}
	for(i=1;i<=m;i++)
	    for(j=1;j<=n;j++)
	        if(c[i][j]==x){cout<<i<<" "<<j; break;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
