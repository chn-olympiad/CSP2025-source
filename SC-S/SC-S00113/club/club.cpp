#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+15;
struct node{
	ll v,id;
}a[N][4];
bool cmp(node x,node y)
{
	return x.v>y.v;
}
ll q[4][N],cnt[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		ll ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1].v,&a[i][2].v,&a[i][3].v);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+1+3,cmp);
			ll k=a[i][1].id;
			q[k][++cnt[k]]=a[i][1].v-a[i][2].v;
			ans+=a[i][1].v;
		}
		for(ll i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				sort(q[i]+1,q[i]+1+cnt[i]);
				for(ll j=1;j<=cnt[i]-(n/2);j++)
				{
					ans-=q[i][j];
				}
			}	
			cnt[i]=0;	
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/