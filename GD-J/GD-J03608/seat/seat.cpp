#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x=0,c,r;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=a[1]) x++;
	}
	c=(x+n-1)/n;
	if(x%n==0) r=n;
	else r=x%n;
	if(c%2==0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
