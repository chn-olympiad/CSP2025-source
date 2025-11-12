#include<bits/stdc++.h>
using namespace std;
const long long MAXN=15;
long long n,m,a[MAXN*10],wh;
bool cmp(long long g,long long h)
{
	return g>=h;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%lld",&a[i]);
	wh=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(wh==a[i])
		{
			wh=i;
			break;
		}
	}
	long long x=(wh+n-1)/n,y=wh%n;
	if(y==0)
		y=n;
	if(x%2==0)
		y=n-y+1;
	if(y==0)
		y=1;
	printf("%lld %lld",x,y);
	return 0;
} 
