#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500000+10];
struct node{
	ll l,r;
}f[10000000];
bool cmp(const node &x,const node &y){
	return x.r<y.r;
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
	for(ll i=1;i<=n-1;i++){
		ll x=a[i];
		if(x==k){
			f[++t].l=i;
			f[t].r=i;
		}
		for(ll j=i+1;j<=n;j++){
			x^=a[j];
			if(x==k){
				f[++t].l=i;
				f[t].r=j;
			}
		}
	}
	ll c=1;
	sort(f+1,f+t+1,cmp);
	ll R=f[1].r;
	for(ll i=2;i<=t;i++){
		if(f[i].l>R){
			c++;
			R=f[i].r;
		}
	}
	cout<<c<<"\n";
	return 0;
}
