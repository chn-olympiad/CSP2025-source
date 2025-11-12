#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],f[5010],g[5010],bit[5010],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bit[0]=1;
	for(int i=1;i<=n;i++){
		bit[i]=bit[i-1]*2%mod;
	}
	f[0]=1;
	for(int i=0;i<=5000;i++){
		g[i]=1;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		ans+=bit[i]-g[a[i]];
		ans=(ans%mod+mod)%mod;
		for(int j=5000;j>=a[i];j--){
			f[j]+=f[j-a[i]];
		}
		for(int j=1;j<=5000;j++){
			g[j]=(g[j-1]+f[j])%mod;
		}
	}
	cout<<ans;
	return 0;
}