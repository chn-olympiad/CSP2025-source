#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],z=0,ji=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	z=a[0],sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
		if(a[i]==z)
		{
			ji=n*m-i;
			break;
		}
	cout<<(ji-1)/n+1<<" ";
	if((ji-1)/n%2==0)
		cout<<ji-int((ji-1)/n)*n;
	else 
		cout<<m-(ji-int((ji-1)/n)*n-1);
	return 0;
 } 
