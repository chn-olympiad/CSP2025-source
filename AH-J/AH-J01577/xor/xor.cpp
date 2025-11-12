//呃啊
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],sum[500010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		sum[i]=(sum[i-1]^a[i]);
	}
	ll R=0;
	for(ll r=1;r<=n;r++){
		for(ll l=1;l<=r;l++){
			if((sum[r]^sum[l-1])==k&&l>R){
				//cout<<l<<' '<<r;
				R=r;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
