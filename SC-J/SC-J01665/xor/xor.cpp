#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005];
ll n,k;
ll ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
 	cin>>n>>k;
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int xorsum=a[i];
		if(xorsum==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]==k)break;
			xorsum = (xorsum ^ a[j]);
			if(xorsum==k){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}