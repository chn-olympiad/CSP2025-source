#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
struct node
{
	ll r1,r2,r3;
	ll c;
};
ll q;
ll n,cnt[5],ans=0;
node a[100005];
void pis(ll t)
{
	priority_queue<pii,vector<pii>,greater<pii>> q;
	if(t==1)
	{
		for(ll i=1;i<=n;i++)if(a[i].c==1)q.push({a[i].r1-max(a[i].r2,a[i].r3),i});
		while(cnt[1]*2>n)
		{
			auto u=q.top();
			q.pop();
			ll p=max(a[u.second].r2,a[u.second].r3);
			if(p==a[u.second].r2)cnt[1]--,ans=ans-u.first;
			else cnt[1]--,ans=ans-u.first;
		}
	}
	else if(t==2)
	{
		for(ll i=1;i<=n;i++)if(a[i].c==2)q.push({a[i].r2-max(a[i].r1,a[i].r3),i});
		while(cnt[2]*2>n)
		{
			auto u=q.top();
			q.pop();
			ll p=max(a[u.second].r1,a[u.second].r3);
			if(p==a[u.second].r1)cnt[2]--,ans=ans-u.first;
			else cnt[2]--,ans=ans-u.first;
		}
	}
	else
	{
		for(ll i=1;i<=n;i++)if(a[i].c==3)q.push({a[i].r3-max(a[i].r1,a[i].r2),i});
		while(cnt[3]*2>n)
		{
			auto u=q.top();
			q.pop();
			ll p=max(a[u.second].r1,a[u.second].r2);
			if(p==a[u.second].r1)cnt[3]--,ans=ans-u.first;
			else cnt[3]--,ans=ans-u.first;
		}
	}
}
void query()
{
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].r1,&a[i].r2,&a[i].r3);
		ll p=max(a[i].r1,max(a[i].r2,a[i].r3));
		if(p==a[i].r1)a[i].c=1,cnt[1]++,ans+=p;
		else if(p==a[i].r2)a[i].c=2,cnt[2]++,ans+=p;
		else a[i].c=3,cnt[3]++,ans+=p;
	}
	if(cnt[1]*2>n)pis(1);
	else if(cnt[2]*2>n)pis(2);
	else if(cnt[3]*2>n)pis(3);
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		query();
	}
	
	return 0;
}
