#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,k,a[N],pre[N];
struct lr
{
	int l,r;
	bool friend operator<(lr x,lr y)
	{
		if(x.r==y.r)
		  return x.l>y.l;
		return x.r<y.r;
	}
}mp[10000005];
int nmp;

void tle60()
{
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((pre[j]^pre[i-1])==k)
			  mp[++nmp]={i,j};
	sort(mp+1,mp+nmp+1);
	int p=0,ans=0;
//	for(int i=1;i<=nmp;i++)
//	  printf("%lld %lld\n",mp[i].l,mp[i].r);
	for(int i=1;i<=nmp;i++)
		if(mp[i].l>p)
		  ans++,p=mp[i].r;
//	int l=0,r=n+1,mid,ans;
//	while(l<=r)
//	{
//		mid=l+(r-l)/2;
//		if(check60(mid))
//		  ans=mid,l=mid+1;
//		else
//		  r=mid-1;
//	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]),pre[i]=(pre[i-1]^a[i]);
//	if(n<=5000)
//	{
		tle60();
		return 0;
//	}
}
