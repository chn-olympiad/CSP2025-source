#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c,r,pm;
struct students
{
	int score,id;
}a[10001];
bool px(students x,students y)
{
	return x.score>y.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].score);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,px);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i].id==1)
		{
			pm=i;
			break;
		}
	}
	if(pm%n!=0)
	{
		c=pm/n+1;
		r=pm%n;
	}
	else
		if(pm%n==0)
		{
			c=pm/n;
			r=n;
		}
	if(c%2==0)
	{
		r=n-r+1;
	}
	printf("%d %d",c,r);
	return 0;
}

