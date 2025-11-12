#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c=1,d=1; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&b);
		if(b>a)c++;
	}
	while(c>n)
	{
		c-=n;
		d++;
	}
	printf("%d ",d);
	if(d%2==0)printf("%d ",n-c+1);
	else printf("%d ",c);
	return 0;
}
