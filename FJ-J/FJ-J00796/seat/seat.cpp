#include<bits/stdc++.h>
using namespace std;
struct node{
	int k;
	int d;
	int p;
};
node a[105];
bool cmp(node x,node y)
{
	return x.k>y.k;
}
bool cmp1(node x,node y)
{
	return x.d<y.d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int h=n*m;
	for(int i=1;i<=h;i++)
	{
		scanf("%d",&a[i].k);
		a[i].d=i;
	}
	sort(a+1,a+1+h,cmp);
	for(int i=1;i<=h;i++)
	{
		a[i].p=i;
	}
	sort(a+1,a+1+h,cmp1);
	int c=ceil(a[1].p*1.0/n);
	int r=a[1].p%n;
	if(r==0)
		r=n;
	if(c%2==1)
		printf("%d %d",c,r);
	else
		printf("%d %d",c,n-r+1);
	return 0;
}
