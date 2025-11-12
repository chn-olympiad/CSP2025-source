#include<bits/stdc++.h>
using namespace std;
int n,m,tot,s,pos,r,c,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m),tot=n*m;
	for(int i=1;i<=tot;i++) scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+1+tot);
	for(int i=1;i<=tot;i++) if(a[i]==s)
	{
		pos=n*m-i+1;
		break;
	}
	c=(pos-1)/n+1;
	if(pos%n==0)
	{
		if(c&1) r=n;
		else r=1;
	}
	else
	{
		if(c&1) r=pos%n;
		else r=n-pos%n+1;
	}
	printf("%d %d",c,r);
	return 0;
}
