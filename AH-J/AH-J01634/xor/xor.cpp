#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
	ll l,r;
}t[500005];
ll xo[500005];
bool cmp(const st& x,const st& y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,cn=0,a;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a;
		xo[i]=xo[i-1]^a;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll sumx=xo[j]^xo[i-1];
			if(sumx==k){
				cn++;
				t[cn].l=i;	
				t[cn].r=j;
			}
		}
	}
	sort(t+1,t+cn+1,cmp);
	ll R=t[1].r;
	ll cnt=1;
	for(ll i=2;i<=cn;i++){
		if(t[i].l>R){
			cnt++;
			R=t[i].r;
		}
	}
	cout<<cnt;
	return 0;
}

