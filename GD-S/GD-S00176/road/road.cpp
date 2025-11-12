#include<bits/stdc++.h>
typedef long long ll;
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define mem0(s) memset(s,0,sizeof(s))
#define memf(s) memset(s,0x7f,sizeof(s))
using namespace std;
const int N = 1e6+10;
const ll M = 1e9+10;
ll n,m,k,cnt;
struct node{
	ll to,len,next;
}e[N];
ll head[N];
void add(ll u,ll v,ll w){
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
ll cj[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	ll a,b,c;
	ll ans=1e18,sum=0;
	f(i,1,m){
		scanf("%lld%lld%lld",&a,&b,&c);
		sum+=c;
		add(a,b,c);
		add(b,a,c);
	}
	ans=min(ans,sum);
	f(i,1,k){
		scanf("%lld",&cj[i]);
		ll x;
		sum=0;
		f(j,1,n){
			cin>>x;
			add(n+i,j,x);
			add(j,n+i,x);
			sum+=x;
		}
		ans=min(ans,sum+cj[i]);
	}
	printf("%lld",ans); 
	return 0;
}

