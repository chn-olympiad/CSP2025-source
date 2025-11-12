#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll T,n,ans,ca,cb,cc,pos,cnt;
struct st
{
	ll val,id;
}a[N][5];
struct data
{
	ll val,id;
}b[N];
bool cmp(st x,st y)
{
	if(x.val!=y.val) return x.val>y.val;
	return x.id<y.id;
}
bool cmp2(data x,data y)
{
	return x.val<y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%lld",&a[i][j].val);
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+3+1,cmp);
		}
		ans=ca=cb=cc=pos=cnt=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][1].val;
			if(a[i][1].id==1) ca++;
			if(a[i][1].id==2) cb++;
			if(a[i][1].id==3) cc++;
		}
		if(ca<=n/2&&cb<=n/2&&cc<=n/2)
		{
			printf("%lld\n",ans);
			continue;
		}
		if(ca>n/2) pos=1;
		else if(cb>n/2) pos=2;
		else pos=3;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1].id==pos)
			{
				b[++cnt].val=a[i][1].val-a[i][2].val;
				b[cnt].id=i;
			}
		}
		sort(b+1,b+cnt+1,cmp2);
		ll up;
		if(pos==1) up=ca-n/2;
		if(pos==2) up=cb-n/2;
		if(pos==3) up=cc-n/2;
		for(int i=1;i<=up;i++)
		{
			ans-=b[i].val;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
