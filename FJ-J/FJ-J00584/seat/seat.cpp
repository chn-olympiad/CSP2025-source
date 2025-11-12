#include<bits/stdc++.h>
using namespace std;
int s,seat=1,x,yy,xx;
int m,n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n*m;++i)
	{
		scanf("%d",&x);
		if(x>s) seat++;
	}
	yy=seat%n;
	if(yy==0) yy=n;
	xx=ceil(seat*1.0/n);
	if(xx%2==0) yy=n+1-yy;
	printf("%d %d",xx,yy);
	return 0;
}
