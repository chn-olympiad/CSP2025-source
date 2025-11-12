#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s[5005],sum[5005],mx[5005],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		sum[i]=sum[i-1]+s[i];
		mx[i]=max(mx[i-1],s[i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+2;j<=n;j++){
			if(sum[j]-sum[i-1]>=mx[j]*2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
