#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],n,k;
ll xum(int l,int r){
	ll ans=0;
	if(l==r) return a[l];
	else{
		for(ll i=l;i<=r;i++){
			ans=int(ans^a[i]);
		}
		return ans;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(xum(i,j)==k){
			//	cout<<i<<'-'<<j<<endl;
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}