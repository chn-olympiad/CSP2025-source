#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=1e5+114;
int n;
ll a[N][3],b[N],v[N]; // clear!
ll cnt[3];

void xzm()
{
	cin>>n;
	std::fill(cnt,cnt+3,0);
	std::fill(v,v+n+1,0);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
		b[i]=std::max_element(a[i],a[i]+3)-a[i];
		cnt[b[i]]++;
		ans+=a[i][b[i]];
	}
	ll x=std::max_element(cnt,cnt+3)-cnt;
	if(cnt[x]<=n/2)return void(printf("%lld\n",ans));
	ll y=cnt[x]-n/2;
	// assert(y<=n);
	// fprintf(stderr,"%lld\n",y);
	for(int i=1;i<=n;i++)
	{
		if(b[i]==x)v[i]=a[i][x]-(a[i][0]+a[i][1]+a[i][2]-std::min({a[i][0],a[i][1],a[i][2]})-a[i][x]);
		else v[i]=0x3f3f3f3f;
	}
	std::sort(v+1,v+n+1);
	// for(int i=1;i<=n;i++)fprintf(stderr,"*%d %d\n",v[i],b[i]);
	ll sum=std::accumulate(v+1,v+y+1,0ll);
	printf("%lld\n",ans-sum);
}

int main()
{
	fr(club)
	cin.tie(nullptr)->sync_with_stdio(false);
	int sto=1;
	cin>>sto;
	while(sto--)xzm();
	return 0;
}
