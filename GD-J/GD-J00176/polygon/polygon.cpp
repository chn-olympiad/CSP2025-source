#include<bits/stdc++.h>
typedef long long ll;
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define mem0(p) memset(p,0,sizeof(p))
#define memf(p) memset(p,0x7f,sizeof(p))
#define fs first
#define sc second
#define pb push_back
#define pii pair<ll,ll>
using namespace std;
const int N = 2e6 + 10;
const ll M = 998244353;
ll n,m;
ll a[N];
ll p[N];
ll cnt;
ll ans=0;
void print(ll cnt){
	ll maxn=-1,sum=0;
	f(i,1,cnt){
		sum+=p[i];
		maxn=max(maxn,p[i]);
	}
	if(sum>2*maxn) ans=(ans+1)%M;
	return;
}
void dfs(ll x,ll cnt){
	if(x>n){
		if(cnt>2) 
		print(cnt);
		return;
	}
	p[++cnt]=a[x];
	dfs(x+1,cnt);
	p[cnt]=0;
	dfs(x+1,cnt-1);
	return; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	f(i,1,n){
		scanf("%lld",&a[i]);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
