#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n;
struct Node{
	ll a,b;
}a[100005][4];
bool cmp(Node a,Node b){return (a.a==b.a?(a.b>=b.b):(a.a>=b.a));}
int cnt[4];
ll js[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ll ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1].a,&a[i][2].a,&a[i][3].a);
			a[i][1].b=1,a[i][2].b=2,a[i][3].b=3;
			sort(a[i]+1,a[i]+1+3,cmp);
			cnt[a[i][1].b]++;
			ans+=a[i][1].a;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			printf("%lld\n",ans);
			continue;
		}
		int nw=0;
		if(cnt[1]>n/2) nw=1;
		else if(cnt[2]>n/2) nw=2;
		else nw=3;
		int cntt=0;
		for(int i=1;i<=n;i++)
			if(a[i][1].b==nw)
				js[++cntt]=a[i][1].a-a[i][2].a;
		sort(js+1,js+1+cntt);
		for(int i=1;i<=cnt[nw]-n/2;i++) ans-=js[i];
		printf("%lld\n",ans);
	}
}
