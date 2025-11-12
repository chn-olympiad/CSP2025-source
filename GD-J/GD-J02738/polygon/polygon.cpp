#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,ma,ans,l,r;
ll a[100005],b[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		if(a[1]+a[2]+a[3]>2*ma) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<3) cout<<0;
	b[0]++,b[a[1]]++,b[a[2]]++,b[a[1]+a[2]]++;
	r=a[1]+a[2];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		l=a[i]+1;
		for(int j=l;j<=r;j++){
			if(b[j]) ans=(ans+b[j])%mod;
		}
		for(int j=r;j>=0;j--){
			if(b[j]) b[j+a[i]]=(b[j+a[i]]+b[j])%mod;
		}
		r+=a[i];
	}
	cout<<ans;
	return 0;
} 
