#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M=5e5+5;
ll n,k,a[M],ans=0;
bool flag=1;
ll jia(int l,int r){
	ll temp=a[l];
	for(int i=l+1;i<r;i++) temp=temp^a[i]; 
	return temp;
}
bool check(ll l,ll m,ll r){
	ll cnt=jia(l,r);
	if(cnt==k){
		ans=max(ans,r-l+1);
		return 1;
	}
	else return 0;
}
void solve1(){
	if(n==1) cout<<0;
	else if(n==2) cout<<2;
}
void solve2(){
	if(n%2==0) cout<<n;
	else cout<<n-1;
}
void solve3(){
	ll ans1=0;
	for(int i=1;i<=n;i++) if(a[i]==k) ans1++;
	cout<<ans1;
}
void solve4(){
	ll l=1,r=n,m=0;
	while(l!=r){
		m=(l+r)/2;
		if(check(l,m,r)) l=m+1;
		else r=m;
	}
	cout<<ans;
}
void solve(){
	bool c=1;
	for(int i=1;i<=n;i++) if(a[i]!=1){c=0;break;}
	if(c==0) solve3();
	else{
		if(n<=2) solve1();
		else solve2();
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=0 && a[i]!=1){
			flag=0;
			break;
		}
	}
	if(flag) solve();
	else{
		if((n/k)%2==0) solve4();
		else solve3();
	}
	return 0;
}
