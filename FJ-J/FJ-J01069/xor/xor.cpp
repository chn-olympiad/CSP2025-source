#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500100],b[3048576],t;
struct w{
	long long x,y;
}f[500100];
bool ww(w a,w b)
{
	if(a.y==b.y) 
		return a.x<b.x;
	return a.y<b.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=(1<<20);i>=0;i--)
		b[i]=-1;
	b[0]=0;
	for(long long i=1;i<=n;i++)
	{
		long long u=a[i]^k;
		if(b[u]!=-1)
		{
			f[++t].x=b[u]+1;
			f[t].y=i;
		}
		b[a[i]]=i;
	}
//	sort(f+1,f+t+1,ww);
	long long s=0,r=-1;
	for(long long i=1;i<=t;i++)
	{
		if(f[i].x<=r)continue;
		r=f[i].y;
		s++;
	} 
	printf("%lld\n",s);
	return 0;
}
