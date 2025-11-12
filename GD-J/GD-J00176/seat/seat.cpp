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
const int N = 1e5 + 10;
const ll M = 1e9 + 10;
ll n,m;
pii re[N];
vector<ll> v;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll x;
	f(i,1,n){
		f(j,1,m){
			scanf("%lld",&x);
			v.pb(x);
		}
	}
	ll tmp=v[0];
	sort(v.begin(),v.end(),cmp);
	bool ff=1;
	ll id=0;
	f(i,1,n){
		if(ff){
			ff=0;
			f(j,1,m){
				re[v[id]]={i,j};
				id++;
			} 
		}
		else{
			ff=1;
			f_(j,m,1){
				re[v[id]]={i,j};
				id++;
			}
		}
	}
	printf("%lld %lld",re[tmp].fs,re[tmp].sc);
	return 0;
}
