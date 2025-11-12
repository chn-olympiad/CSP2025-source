#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define PB push_back
const int N=5005,P=998244353 ;
ll m,n,cnt,ex,ans;
ll a[N],c[N],p[N];
vector<ll> b;
bool fl;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)scanf("%lld",a+i);
	sort(a+1,a+1+m);
	for(ll i=1;i<(1<<n);i++){
		for(ll x=i,j=1;x;x>>1,j++) if(a[j]*(x&1)!=0) b.PB(a[j]);
		ll sum=0,mx;
		if(b.size()<3) continue;
		for(int j=0;j<b.size();j++) sum+=b[j],mx=max(b[j],sum);
		if(sum>mx*2) ans=(ans+1)%P;
	}
	cout<<ans;
	return 0;
	}
/**/

