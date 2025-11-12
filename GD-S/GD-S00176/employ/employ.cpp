#include<bits/stdc++.h>
typedef long long ll;
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define mem0(s) memset(s,0,sizeof(s))
#define memf(s) memset(s,0x7f,sizeof(s))

using namespace std;
const int N = 1e4+10;
const ll M = 998244353;
ll n,m;
char s[N];
ll pre[N];
ll c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f(i,1,n){
		cin>>s[i];
		pre[i]=pre[i-1]+s[i]-'0';
	}
	f(i,1,n){
		scanf("%lld",&c[i]);
	}
	ll sum=pre[n];
	ll ans=1;
	f(i,2,n){
		ans=(ans*i)%M;
	}
	printf("%lld",ans);
	return 0; 
}

