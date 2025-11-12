#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=15,NN=105;
int n,m;
struct stu
{
	int id,p;
	bool friend operator<(stu x,stu y) {return x.p>y.p;}
}a[NN];

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	  scanf("%lld",&a[i].p),a[i].id=i;
	sort(a+1,a+n*m+1);
	int tt=0;
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1)
		{
			tt=i;
			break;
		}
	int c,r;
	c=(tt-1)/n+1;
	if(c%2)
	  r=(tt-1)%n+1;
	else
	  r=n-((tt-1)%n+1)+1;
	return !printf("%lld %lld\n",c,r);
}
