#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],s=0,w=0,c=0,r=0;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s) 
		{
			w=i;
			break;
		}
	c=w/n,r=w%n;
	if(r==0)
		printf("%lld %lld",c,n);
	else
	{
		if(c%2!=0) printf("%lld %lld",c+1,n-r+1);
		else printf("%lld %lld",c+1,r);
	}
	return 0; 
} 
//检查*1，还有40分钟 
