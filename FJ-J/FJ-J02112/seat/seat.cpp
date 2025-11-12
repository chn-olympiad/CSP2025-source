#include<bits/stdc++.h>
using namespace std;
struct se
{
	int num;
	bool b=0;
}a[105];
bool cmp(se a,se b)
{
	return a.num>b.num;
}
int n,m,t,ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
	}
	a[1].b=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].b) t=i;
	ans1=(t-1)/n+1;
	ans2=t%n;
	if(!ans2) ans2=n;
	if(!(ans1%2))
		ans2=n-ans2+1;
	printf("%d %d",ans1,ans2);
	return 0;
}
