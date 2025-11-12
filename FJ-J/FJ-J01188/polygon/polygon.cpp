#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],ans,num[5005],maxx=-1,yh[5005][5005];
void init(){
	for(ll i=1;i<=n+1;i++){
		for(ll j=1;j<=i;j++){
			if(j==1) yh[i][j]=1;
			else yh[i][j]=(yh[i-1][j]+yh[i-1][j-1])%mod;
		}
	}
}
void dfs(ll k,ll sum,ll x){
	if(num[k-1]+k-x+1>n) return;
	if(k==x){
		ll l=num[k-1]+1,r=n,mid=0,ans1=-1;
		while(l<=r){
			mid=(l+r)/2;
			if(sum+a[mid]>a[mid]*2){
				l=mid+1;
				ans1=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(ans1!=-1) ans=(ans+ans1-num[k-1])%mod;
		
		return;
	}
	for(ll i=num[k-1]+1;i<=n;i++){
		num[k]=i;
		dfs(k+1,sum+a[i],x);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	} 
	if(maxx==1){
		init();
		for(ll i=3;i<=n;i++){
			ans=(ans+yh[n+1][i+1])%mod;
		}
		printf("%lld\n",ans%mod);
	}
	else{
		ans=0;
		sort(a+1,a+n+1);
		for(ll i=3;i<=n;i++){
			dfs(1,0,i);
		}
		printf("%lld",ans%mod);
	}
	return 0;
}
