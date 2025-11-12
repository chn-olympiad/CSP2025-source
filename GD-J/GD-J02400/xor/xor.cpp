#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,k;
ll a[N];
ll f[N];
struct node{
	ll l,r;
}Xo[N];
ll cnt;
ll dp[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
ll find(ll x){
	ll l=1,r=x-1;
	ll res=0;
	while(l<=r){
		ll mid=l+r>>1;
		if(Xo[mid].r<Xo[x].l){
			res=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	ll mxxx=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		f[i]=(f[i-1]^a[i]);
		mxxx=max(mxxx,a[i]);
	}
	if(mxxx<=1 && n>1000){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		if(k==0){
			ans=n-ans;
			int x=1;
			while(x<=n){
				while(a[x]==0 && x<=n) x++;
				if(x>n) break;
				int res=0;
				while(a[x]==1 && x<=n){
					res++;
					x++;
				}
				ans+=res/2;
			}
			cout<<ans;
		}else{
			cout<<ans;
		}
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				cnt++;
				Xo[cnt].l=i;
				Xo[cnt].r=j;
				break;
			}
		}
	}
	sort(Xo+1,Xo+cnt+1,cmp);
	dp[1]=1;
	for(ll i=2;i<=cnt;i++){
		ll p=find(i);
		dp[i]=max(dp[i-1],dp[p]+1);
	}
	cout<<dp[cnt];
	return 0;
}
