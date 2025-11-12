#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int s,y;
}a[105];
bool cmp(stu a,stu b)
{
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i].s;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int j;
	for(int i=1;i<=n*m;++i)
	{
		if(a[i].y==1)
		{
			j=i;
			break;
		}
	}
	if(j%n==0)
	{
		printf("%lld ",j/n);
		if(j/n%2==1) printf("%lld",n);
		else printf("1");
	}
	else
	{
		printf("%lld ",j/n+1);
		if((j/n+1)%2==1) printf("%lld",j%n);
		else printf("%lld",(j/n+1)*n+1-j);
	}
	return 0;
}
