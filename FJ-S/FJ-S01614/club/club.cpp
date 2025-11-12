#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct str
{
	ll val;
	ll pos;
};
bool cmp(str a,str b)
{
	return a.val>b.val;
};
bool cmp2(str a,str b)
{
	if(a.pos==b.pos) return a.val<b.val;
	return a.pos<b.pos;
};
ll T;
str l[10005][4];
str genshin[10005];
ll cnt[4]={0,0,0,0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		for(int i=0;i<=10001;i++)
			for(int j=0;j<=3;j++)
				l[i][j].val=0;
		for(int i=0;i<=10001;i++)
			genshin[i].val=0;
		for(int i=0;i<=3;i++)
			cnt[i]=0;
		ll n;
		ll ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&l[i][1].val,&l[i][2].val,&l[i][3].val);
			l[i][1].pos=1;
			l[i][2].pos=2;
			l[i][3].pos=3;
			sort(l[i]+1,l[i]+n+1,cmp);
			cnt[l[i][1].pos]++;
			ans+=l[i][1].val;
			genshin[i].val=l[i][1].val-l[i][2].val;
			genshin[i].pos=l[i][1].pos;
		}
		sort(genshin+1,genshin+n+1,cmp2);
		if(cnt[1]>(n>>1))
		{
			for(int i=1;cnt[1]>(n>>1);i++,cnt[1]--) ans-=genshin[i].val;
		}
		if(cnt[2]>(n>>1))
		{
			int i=1;
			for(;genshin[i].pos!=2;i++);
			for(;cnt[2]>(n>>1);i++,cnt[2]--) ans-=genshin[i].val;
		}
		if(cnt[3]>(n>>1))
		{
			int i=1;
			for(;genshin[i].pos!=3;i++);
			for(;cnt[3]>(n>>1);i++,cnt[3]--) ans-=genshin[i].val;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
