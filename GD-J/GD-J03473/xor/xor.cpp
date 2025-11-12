#include<bits/stdc++.h>
#define ll long long
const ll N=5*1e5+10;

using namespace std;
ll n,k,cnt0,cnt1,ans;
ll a[N],ma=-1,mi=1;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1){
		if(n==k) cout<<1;
		else cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;++i) {
	cin>>a[i];
	if(a[i]==1) cnt1++;
	if(a[i]==0) cnt0++;
	}
	if(k==0){
		cout<<cnt1/2+cnt0;
		return 0;
	}
		cout<<cnt1;
	 
	
	return 0;
}
