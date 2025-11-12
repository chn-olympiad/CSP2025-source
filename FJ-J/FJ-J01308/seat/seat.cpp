#include<bits/stdc++.h>
using namespace std;
int a[100005];
int t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+1+n*m);
	int pos=lower_bound(a+1,a+1+n*m,t)-a;
	pos=n*m+1-pos;
	int c=(pos+n-1)/n,r=0;
	if(c%2==1) r=(pos-1)%n+1;
	else r=n-(pos-1)%n;
	printf("%d %d\n",c,r);
	return 0;
}
