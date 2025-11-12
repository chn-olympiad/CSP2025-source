#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
struct node
{
	long long l,r;
}s[N];
bool cmp(node a,node b)
{
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
long long n,k,a[N],ans,cnt,mr;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i!=1)a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((long long)(a[j]^a[i-1])==k)s[++cnt]=(node){i,j};
		}
	}
	sort(s+1,s+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{  
		printf("%lld %lld\n",s[i].l,s[i].r);
		if(mr<s[i].l)
		{
		  	ans++;
	    	mr=s[i].r;
	    }
	}
	printf("%lld",ans);
	return 0;
}
