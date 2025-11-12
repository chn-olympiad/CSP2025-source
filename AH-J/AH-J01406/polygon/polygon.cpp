#include<bits/stdc++.h>
using namespace std;
int n,a[5005],vis[5005];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int maxn=0,all=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		all+=a[i];
		if(a[i]>1) flag=false;
	}
	if(n==3){
		if(all>2*maxn) cout<<1;
		else cout<<0;
	}
	if(flag==true){
		int ans=0;
		for(int i=n;i>=3;i--){
			long long sum=1;
			for(int j=n;j>=n-i+1;j--) sum=(sum*j/(n-j+1))%mod;
			ans=(ans+sum)%mod;
		}
		cout<<ans;
	}
	else{
		cout<<n;
	}
	return 0;
}
