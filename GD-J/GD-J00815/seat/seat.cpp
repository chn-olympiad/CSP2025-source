#include<bits/stdc++.h>
using namespace std;
int n,m,xm;
int a[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	xm=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	xm=find(a+1,a+n*m+1,xm)-a;
	int t=xm/n,u=xm%n;
	if(u==0)
	{
		printf("%d ",t);
		if(t&1)
			printf("%d",n);
		else
			printf("1");
	}
	else
	{
		printf("%d ",t+1);
		if((t+1)&1)
			printf("%d",u);
		else
			printf("%d",n-u+1);
	}
	return 0;
}

