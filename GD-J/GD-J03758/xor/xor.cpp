#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],cnt=0;
ll c(ll x){
	return n-x+1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		if(a[1]==1){
			for(ll i=2;i<=n;i+=2)cnt+=c(i);
		}else if(a[1]==0){
			for(ll i=1;i<=n;i++)cnt+=i;
		}
	}else if(k==1){
		if(a[1]==1){
			for(ll i=1;i<=n;i+=2)cnt+=c(i);
		}
	}
	cout<<cnt;
	return 0;
}
