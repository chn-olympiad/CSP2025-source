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
const int N = 1e6 + 10;
const ll M = 1e9+10;
ll n,k;
ll a[N];
ll pre[N];
struct node{
	ll l,r;
	bool operator<(const node& other)const{
		return r>other.r;
	}
};
priority_queue<node> hp;
vector<ll> v[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	v[0].pb(0);
	f(i,1,n){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]^a[i];
		ll tmp=pre[i]^k;
		if(v[tmp].size()){
			ll len=v[tmp].size()-1;
			ll o=v[tmp][len];
			hp.push({o+1,i});
		}
		v[pre[i]].pb(i);
	}
	ll cnt=0;
	while(!hp.empty()){
		node tmp=hp.top();hp.pop();
		ll r=tmp.r;
		while(!hp.empty()&&hp.top().l<=r) hp.pop();
		cnt++;
	}
	printf("%lld",cnt);
	return 0;
}
