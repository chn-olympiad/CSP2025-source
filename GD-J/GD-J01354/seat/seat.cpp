#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],gra,xr; 
bool cmp (int c1,int c2)
{
	return c1>c2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	gra=a[1];
	sort(&a[1],&a[n*m]+1,cmp);
	for(int i=1;i<=n*m;i++) 
		if(a[i]==gra)
		{
			xr=i;
			break;
		}
	if(xr%n==0)
	{
		if((xr/n)%2==0)
			cout<<xr/n<<" "<<"1"<<endl;
		else
			cout<<xr/n<<" "<<n<<endl; 
	}
	else
	{
		if((xr/n)%2==0)
		    cout<<xr/n+1<<" "<<xr%n;
		else
		    cout<<xr/n+1<<" "<<n-xr%n+1;
	}
	return 0;
}
