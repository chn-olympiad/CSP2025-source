#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> recor;
int cnt;
int n,k,lcnt=0;
int a[500101],sum[500101],ans[500101];
struct node
{
	int l,r;
}ls[500101],use[500101];
bool cmp(node x,node y)
{
	return x.l>y.l||(x.l==y.l&&x.r<y.r);
}
bool cmp2(node x,node y)
{
	return x.l<y.l||(x.l==y.l&&x.r<y.r);
}
int dfs(int x)
{
	if(x>cnt)
		return 0;
	if(ans[x]!=-1)
		return ans[x];
	int lef=x+1,rig=cnt+1,en=cnt+1;
	while(lef<=rig)
	{
		int mid=lef+rig>>1;
		if(use[mid].l>use[x].r)
		{
			rig=mid-1;
			en=mid;
		}
		else lef=mid+1;
	}
	ans[x]=max(dfs(en)+1,dfs(x+1));
	return ans[x];
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]^a[i];
	recor[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(recor[k^sum[i]])
		{
			ls[++lcnt].l=recor[k^sum[i]];
			ls[lcnt].r=i;
		}
		recor[sum[i]]=i+1;
	}
	sort(ls+1,ls+1+lcnt,cmp);
	int ra;
	if(lcnt)
	{
		ra=ls[1].r;
		use[++cnt]=ls[1];
	}
	for(int i=2;i<=lcnt;i++)
		if(ra>ls[i].r)
		{
			use[++cnt]=ls[i];
			ra=min(ra,ls[i].r);
		}
	for(int i=1;i<=cnt;i++)
		ans[i]=-1;
	sort(use+1,use+1+cnt,cmp2);
	use[cnt+1].l=0x3f3f3f3f;
	printf("%lld",dfs(1));
	return 0;
}
