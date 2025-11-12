#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll a[N],t=0; //统计区间个数
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll flag=0;
		ll ans=0; //当前区间内值的异或和 
		for(ll j=i;j<=n;j++){
			ans=ans^a[j];
			if(ans==k){
				t++;
				ans=0;
				i=j+1;
			}
		}
	}
	cout<<t;
	return 0;
}