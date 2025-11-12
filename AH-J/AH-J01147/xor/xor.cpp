#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500000+10;
ll n,k,a[N],ans,xr[N],dp[10010];
struct str{
	ll l,r;
};
vector<str> v; 
bool cmp(const str x,const str y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		xr[i]=(xr[i-1]^a[i]);
	}
	if(k==0){
		for(ll i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if (a[i]==a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(ll i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				v.push_back({i,j});
			}
		}
	}
	for(ll i=0;i<ll(v.size());i++){
		for(ll j=0;j<=v[i].l;j++){
			dp[v[i].l]=max(dp[v[i].l],dp[j]);
		}
		dp[v[i].r]=max(dp[v[i].r],dp[v[i].l]+1);
		for(ll j=v[i].l;j<v[i].r;j++){
			dp[j]=max(dp[j],dp[v[i].l]);
		}
	}
	for(ll i=0;i<=10000;i++)ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
