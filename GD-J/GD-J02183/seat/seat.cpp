#include<bits/stdc++.h>
using namespace std;
int n,m,b,xm,xmc;
int cj[1145];
int pondd()
{
	int k=xmc,t=0;
	if(k>n)
	while(1)
	{
		t++;
		k-=n;
		if(k<=n)break;
	} 
	return t+1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	b=n*m;
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&cj[i]);
	}
	xm=cj[1];
	sort(cj+1,cj+b+1);
	for(int i=1;i<=b;i++)
	{
		if(cj[i]==xm)
		{
			xmc=b-i+1;
			break;
		}
	}
	int line=pondd(),seat=(xmc-1)%n+1;
	if(line%2==1)
	{
		printf("%d %d",line,seat);
	}
	else
	{
		printf("%d %d",line,n-seat+1);
	}
	return 0;
}
