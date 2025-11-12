#include<bits/stdc++.h>
#define ll long long
#define N 100009
using namespace std;
ll a[N],b[N],c[N];
priority_queue<ll,vector<ll>,greater<ll> >q[4]; 
void solve(){
	ll n,sum=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		ll maxn=max(a[i],max(b[i],c[i]));
		if(maxn==a[i]){
			ll tmx=max(b[i],c[i]),siz=q[1].size();
			if(siz<n/2){
				sum+=a[i];
				q[1].push(maxn-tmx);
				continue;
			}
			ll mn=q[1].top();
			if(sum-mn+maxn>sum+tmx){
				sum=sum-mn+maxn;
				q[1].pop();
				q[1].push(maxn-tmx);
			}
			else sum+=tmx;
		}
		else if(maxn==b[i]){
			ll tmx=max(a[i],c[i]),siz=q[2].size();
			if(siz<n/2){
				sum+=b[i];
				q[2].push(maxn-tmx);
				continue;
			}
			ll mn=q[2].top();
			if(sum-mn+maxn>sum+tmx){
				sum=sum-mn+maxn;
				q[2].pop();
				q[2].push(maxn-tmx);
			}
			else sum+=tmx;
		}
		else{
			ll tmx=max(b[i],a[i]),siz=q[3].size();
			if(siz<n/2){
				sum+=c[i];
				q[3].push(maxn-tmx);
				continue;
			}
			ll mn=q[3].top();
			if(sum-mn+maxn>sum+tmx){
				sum=sum-mn+maxn;
				q[3].pop();
				q[3].push(maxn-tmx);
			}
			else sum+=tmx;
		}
	}
	for(ll i=1;i<=3;i++){
		while(!q[i].empty())q[i].pop();
	}
	printf("%lld\n",sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--)solve();
	return 0;
}
