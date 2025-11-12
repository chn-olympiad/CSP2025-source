#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],s[N];
struct node{
	ll l,r;
}t[N];
bool cmp(node b,node c){
	return b.r<c.r;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll cnt=0;
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=a[1];
	for(ll i=2;i<=n;i++){
		s[i]=(s[i-1]^a[i]);
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==k){
			node tot;
			tot.l=i;
			tot.r=i;
			cnt++;
			t[cnt]=tot;
		}
		for(ll j=i+1;j<=n;j++){
			if((s[j]^s[i-1])==k){
				node tot;
				tot.l=i;
				tot.r=j;
				cnt++;
				t[cnt]=tot;
			}
		}
	}
	ll ans=0,la;
	sort(t+1,t+1+cnt,cmp);
	for(ll i=1;i<=cnt;i++){
		if(i==1){
			ans++;
			la=1;
			continue;
		}
		if(t[i].l>t[la].r){
			ans++;
			la=i;
		}
	}
	cout<<ans;
	return 0;
}