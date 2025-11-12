#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500010],b[500010],c[500010],res=0,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				c[j]=i;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if(c[i]>res){
			ans++;
			res=i;
		}
	}
	cout<<ans;
	return 0;
}
