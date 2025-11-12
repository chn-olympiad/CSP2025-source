#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,a[5005],b[5005],ans,mp[5005],sum[5005];
inline void js(ll mb,ll now,ll xb,ll zd){
	xb++;
	for(;xb<=zd-1;xb++){
		if(now+a[xb]<=mb){
			ans++;
			ans%=mod;
			js(mb,now+a[xb],xb,zd);
		}
		else{
			return;
		}
	}
}
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		for(ll j=i;j>=3;j--){
			if(j==3)mp[3]+=(i-2);
			else mp[j]+=mp[j-1];
			b[i]+=mp[j];
			b[i]%=mod;
		}
		b[i]+=b[i-1];
		b[i]%=mod;
		sum[i]=sum[i-1]+a[i];
	}
	if(sum[n]==n){
		cout<<b[n]%mod;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=3;i<=n;i++){
		for(ll j=1;j<=i-2;j++)js(a[i],a[j],j,i);
	}
	cout<<(b[n]-ans)%mod;
	return 0;
}
