#include<bits/stdc++.h>
using namespace std;
int n,m,id,x,a[10010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(x==a[i])id=i;
	int pai=id/n,lie=id%n;
	if(lie==0)
	{
		printf("%d ",pai);
		if(pai%2==0)printf("1");
		else printf("%d",n);
	}
	else 
	{
		printf("%d ",pai+1);
		if(pai%2==0)printf("%d",lie);
		else printf("%d",n-lie+1);
	}
	return 0;
}
