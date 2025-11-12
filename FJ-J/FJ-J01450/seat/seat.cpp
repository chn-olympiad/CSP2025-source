#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],t,c,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t)
		{
			t=i;
			break;
		}
	c=(t-1)/n+1;
	if(c%2==0) r=(n-t%n+1);
	else r=(t%n);
	if(m==1) c=1;
	if(n==1) r=1;
	if(c>m || c==0) c=m;
	if(r>n || r==0) r=n;
	printf("%d %d",c,r);
	return 0;
} 
