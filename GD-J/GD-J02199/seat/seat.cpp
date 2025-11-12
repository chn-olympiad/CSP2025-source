#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,t;
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(t=1;a[t]!=x;t++);
//	printf("%d\n",t);
	if(t%n==0)
		printf("%d %d",t/n,(t%(2*n))==0?1:n);
	else
	{
		if(t/n%2==0)
			printf("%d %d",t/n+1,t%n);
		else
			printf("%d %d",t/n+1,n-t%n+1);
	}
	return 0;
}
/*
4 3
12 1 2 3 4 5 6 7 8 9 10 11

12 5 4
11 6 3
10 7 2
9 8 1
*/
