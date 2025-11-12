#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	int a[n*m+1]={0},R,wz;
	for(int i=1;i<=n*m;i++) scanf("%d ",a+i);
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(R==a[i])
		{
			wz=i;
			break;
		}
	int x=wz/n+1,y=0;
	if(wz%n==0) x--;
	if(x%2==0)
	{
		if(wz%n==0) y=1;
		else y=n-(wz%n)+1;
	}
	else
	{
		if(wz%n==0) y=n;
		else y=wz%n;
	}
	printf("%d %d",x,y);
	return 0;
}

