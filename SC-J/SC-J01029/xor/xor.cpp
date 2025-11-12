#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll n,k;
ll a[N];
bool f=1;
ll s[N];
bool flag=0;
ll max1;
void dfs(ll mid,ll num,ll idx){
	if(flag) return; 
	if(num==mid+1){
		s[mid+1]=n+1;
		for(ll i=1;i<=mid;i++){
			ll dig=a[s[i]];
			for(ll j=s[i]+1;j<s[i+1];j++) dig^=a[j];
			if(dig!=k) return;
		}
		flag=1;
		return;
	}
	for(ll i=idx+1;i<=n;i++){
		s[num]=i;
		dfs(mid,num+1,i);
	}
}
bool check(ll mid){
	flag=0;
	dfs(mid,1,0);
	return flag;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
		max1=max(max1,a[i]);
	}
	if(f==1){//a[i]均为1的情况 
		cout<<n/2;
		return 0;
	}
	if(n<=10){
		ll l=1,r=n,ans;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	else if(max1<=1){
		if(k==0){
			ll ans=0,idx=1;
			while(idx<=n){
				if(a[idx]==k){
					ans++;
					idx++;
					continue;
				}
				if(a[idx]==1 and a[idx+1]==1){
					ans++;
					idx+=2;
					continue;
				}
				idx++; 
			}
			cout<<ans;
		}
		else{
			ll ans=0,idx=1;
			while(idx<=n){
				if(a[idx]==k){
					ans++;
					idx++;
					continue;
				}
				idx++;
			}
			cout<<ans;
		}
	}
	else{
		cout<<n/2;
	}
	return 0;
}