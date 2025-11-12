#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll l=1,r=3;r<=n;r++){
		if(a[l]+a[r-1]>=a[r]) sum++;
		if(r==n) l++,r=l+2;
	}
	cout<<sum*2%998244353;
	return 0;
} 
