#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[1000005];
long long s[1000005],b[25000005];
struct Seg
{
	long long l,r;
}c[1000005];
long long tot=0;
bool cmp(Seg a,Seg b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	memset(b,-1,sizeof(b));
	b[0]=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long j=b[s[i]^k];
		if(j!=-1)
		{
			c[++tot]=(Seg){j+1,i};
		}
		b[s[i]]=i;
	}
	sort(c+1,c+tot+1,cmp);
	long long ans=0,now=0;
	for(long long i=1;i<=n;i++)
	{
		if(now<c[i].l)
		{
			now=c[i].r;
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
