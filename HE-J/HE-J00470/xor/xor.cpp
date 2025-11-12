#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],c[500005];
bool flag1=true,flag2=true;
//ll lowbit(ll x){
//	return x&-x;
//}
//void add(ll x,ll p){
//	while(p<=n){
//		c[p]^=x;
//		p+=lowbit(p);
//	}
//}
//ll query(ll l,ll r){
//	ll ans=c[r];
//	r-=lowbit(r);
//	while(r>=l){
//		ans^=c[r];
//		r-=lowbit(r);
//	}
//	return ans;
//}
void solve1(){
	if(n%2==0){
		cout<<n/2;
	}else{
		cout<<0;
	}
}
void solve2(){
	if(k==1){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}else{
		ll ans=0,cnt=0,cnt1=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		if(cnt%2!=0){
			cout<<0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(cnt1!=0){
						cnt1=0;
						ans++;
					}else{
						cnt1++;
					}
				}else{
					if(cnt1==0){
						ans++;
					}
				}
			}
			cout<<ans;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=false;
		}
		if(a[i]>1){
			flag2=false;
		}
	}
	if(flag1&&k==0){
		solve1();
	}else if(flag2){
		solve2();
	}else{
		ll ans=0,cnt=a[1];
		for(ll i=2;i<=n;i++){
			cnt^=a[i];
		}
		if(cnt==k){
			cout<<1;
		}else{
			cout<<2;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
