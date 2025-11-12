#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;
ll n,k,a[N],b[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	ll l=0,r=1;
	while(r<=n){
		ll op = b[r]^b[l];
		if(op==k){
			ans++;
			l = r;
		}
		r++;
	}
	cout<<ans;
	return 0;
}
