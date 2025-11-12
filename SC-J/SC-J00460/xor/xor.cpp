#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
ll a[N],n,k,ans,c,b[N],cnt,ma;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]|a[i];
	}
	if(n<=2&&k==0)  cout<<1;
	if(k<=1) cout<<1;
	for(ll i=1;i<=n;i++){
		ll l,r=n;
		while(l<=r){
			ll mid=l+(r-l)/2;
			if(b[r]-b[l-1]==k)  ma=max(ma,r-l+1);
		}
	}
	cout<<ma;
	return 0;
} 