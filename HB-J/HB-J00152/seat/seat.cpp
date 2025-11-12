#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int mark=a[1],u;
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==mark)
		{
			u=n*m-i+1;
			break;
		}
	}
	int x,y=(u-1)/n+1;
	x=(u-1)%n+1;
	if(y%2==0)
	{
		x=m-x+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
