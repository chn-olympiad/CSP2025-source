#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=1e6;
//异或不同为 1 相同为 0 符号 ^ ; 
ll n,k,ans,pos=2;
ll a[N],b[N];
bool vis[N];
bool yihuo(ll l,ll r){
	for(ll i=l;i<=r;i++){
	    b[i]=a[i];
	}
	for(ll i=l+1;i<=r;i++){
		b[i]=b[i]^b[i-1];
	}
	if(b[r]==k)return true;
	else return false;
}
bool sao(ll l,ll r){
	for(ll i=l;i<=r;i++)if(vis[i]==1)return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){
			ans++;
			vis[i]=1;
		}
	}
	if(n<=2&&k==0){
		cout<<1*(n/2);
		return 0;
	}
	while(pos<n){
	    for(ll i=1;i<=n-pos+1;i++){
	    	ll cnt=i+pos-1;
	    	if(sao(i,cnt)&&yihuo(i,cnt)){
	    		ans++;
	    		for(ll j=i;j<=cnt;j++)vis[j]=1;
			}
    	}
    	pos++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

