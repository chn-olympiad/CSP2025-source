#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],i,j,c,r,x,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	    cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(i=1;i<=n*m;i++)
	    if(a[i]==x){x=i;break;}
	if(x%n==0)c=x/n;
	else c=x/n+1;
	if(c%2==0)
	{
		if(x%n==0)r=1;
		else r=m-x%n+1;
	}
	else
	{
		if(x%n==0)r=m;
		else r=x%n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
