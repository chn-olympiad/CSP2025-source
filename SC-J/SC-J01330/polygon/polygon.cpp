#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5010],f[10010],cm[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	cm[0]=1;
	for(int i=1;i<=n;i++){
		cm[i]=cm[i-1]*2;
		cm[i]%=mod;
	}
	int maxn=-2e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	f[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=maxn*2;j>=a[i];j--){
			f[j]+=f[j-a[i]];
			f[j]%=mod;
		}
//		for(int j=maxn*2;j>=a[i];j--){
//			cout<<f[j]<<' ';
//		}
//		cout<<'\n';
		int tot=0;
		for(int j=1;j<=a[i];j++){
			tot+=f[j];
			tot%=mod;
		}
		ans+=cm[i-1]-tot;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
