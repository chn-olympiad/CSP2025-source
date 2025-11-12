#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
struct cj
{
	int num;
	int b;
}c[105];
bool cmp(cj x,cj y)
{
	if(x.num>y.num)
		return true;
	return false;
}
int t;
int ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; ++i)
	{
		scanf("%d",&c[i].num);
		c[i].b=i;
	}
	sort(c+1,c+1+n*m,cmp);
	
	for(int i=1; i<=n*m; ++i)
	{
		if(c[i].b==1)
			t=i;   
	}
	for(int i=1; i<=m; ++i)
	{
		if(n*i>=t)
		{
			ans1=i;
			break;
		}
	}
	if(ans1%2==1)
		ans2=t-(ans1-1)*n;
	else
		ans2=n-(t-(ans1-1)*n)+1;
		
	printf("%d %d",ans1,ans2);
	return 0;
}
