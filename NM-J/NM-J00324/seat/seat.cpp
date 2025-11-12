#include<bits/stdc++.h>
using namespace std;
struct chengji{int s,mp;}a[1100];
bool cmp(chengji x,chengji y)
{
	return x.s>y.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,num,c=1,r=1;
	scanf("%d%d",&n,&m);
	num=n*m;
	for(i=1;i<=num;++i)
	{
		scanf("%d",&a[i].s);
		a[i].mp=i;
	}
	sort(a+1,a+num+1,cmp);
	for(i=1;i<=num;++i)
	{
		if(a[i].mp==1)
		{
			printf("%d %d\n",r,c);
			return 0;
		}
		if(r%2==1)
		{
			if(c<n) ++c;
			else ++r;
		}
		else
		{
			if(c>1) --c;
			else ++r;
		}
	}
	return 0;
}
