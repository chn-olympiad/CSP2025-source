#include<bits/stdc++.h>
using namespace std;
int a,b,m,n,c,d,i,j,x,y=1;
int g[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	    cin>>g[i];
	c=g[1];
	sort(g+1,g+1+m*n);
	for(i=m*n;i>=0;i--)
	{
		x++;
		if(x>n){
			x=1;
			y++;
		}
		if(g[i]==c)
		{
			cout<<y<<" "<<x;
			fclose(stdin);
	        fclose(stdout);
       		return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
