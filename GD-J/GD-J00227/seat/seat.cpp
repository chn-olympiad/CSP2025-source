#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct P
{
	int id,sc;
}a[119];
bool cmp(P x,P y)
{
	return x.sc>y.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].sc),a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1)
		{
			int x=(i-1)%n+1,y=int((i-1)/n)+1;
		//	cout<<i<<" "<<x<<" "<<y<<" ";
			c=y;
			if(y&1) r=x;
			else r=n-x+1;
			break;
		}
	printf("%d %d",c,r);
	return 0;
}
