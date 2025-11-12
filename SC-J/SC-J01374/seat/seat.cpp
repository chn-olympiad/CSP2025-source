#include<bits/stdc++.h>
using namespace std;
int n,m,a[1200],x=1,t,w;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1])x++;
	}
	t=(x+n-1)/n;
	if(t%2==1)w=x%n;
	else w=n-(x-1)%n;
	if(w==0)w=n;
	printf("%d %d",t,w);
	return 0;
}