#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll x;
	ll y;
}s[5000010];
ll a[5000010];
ll st[5000010];
ll en[5000010];
bool cmp(node p,node q){
	return p.y<q.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll t=0;
	for(ll i=1;i<=n;i++){
		if(a[i]==k){
			t++;
			s[t].x=i;
			s[t].y=i;
		}ll s1=a[i];
		for(ll j=i+1;j<=n;j++){
			s1=s1 xor a[j];
			if(s1==k){
				t++;
				s[t].x=i;
				s[t].y=j;
			}
		}
	}
	sort(s+1,s+t+1,cmp);
	for(ll i=1;i<=t;i++){
		st[i]=s[i].x;
		en[i]=s[i].y;
	}
	ll ans=0;
	for(ll i=1;i<=t;){
		ans++;
		ll u=0;
		for(ll j=i+1;j<=t;j++){
			if(st[j]>en[i]){
				u=1;
				i=j;
				break;
			}
		}
		if(u==0){
			break;
		}
	}
	cout<<ans;
	return 0;
}