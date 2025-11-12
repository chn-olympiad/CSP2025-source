#include<stdio.h>
int _x(int a,int b){return a>b?a:b;}
int a[5005],n,r=0;
void dfs(int sum=0,int max=0,int xu=-1,int ct=0)
{
	if(xu==n)
	{
		if(ct<3)return;
		if(sum>2*max)return(void)(r=(r+1)%998244353);
	}
	sum+=a[xu],max=_x(max,a[xu]);
	for(int i=xu+1; i<=n; ++i)
		dfs(sum,max,i,ct+1);
	return;
}
int main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%d",a+i);
	dfs();printf("%d",r);
	return 0;
}

