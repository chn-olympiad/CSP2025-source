#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[5005],mx,mod=998244353,kv[100005];
int dfs(int x,int s,int cv,long long kl){
	if(x==n+1){
		if(cv>2&&s>kl*2){
			ans++;
		}
		return 0;
	}
	dfs(x+1,s+a[x],cv+1,max(kl,a[x]));
	dfs(x+1,s,cv,kl);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		kv[0]=1;
		kv[1]=1;
		for(int i=2;i<=n;i++){
			kv[i]=(mod-mod/i)*kv[mod%i]%mod;
		}
		long long as=1;
		int jk=1;
		for(int i=n;i>=1;i--){
			as*=i;
			as%=mod;
			as*=kv[jk];
			as%=mod;
			if(jk>=3){
				ans+=as;
				ans%=mod;
			}
			jk++;
		}
		cout<<ans;
	}else if(n<=25){
		dfs(1,0,0,0);
		cout<<ans;
	}else{
		kv[0]=1;
		kv[1]=1;
		for(int i=2;i<=n;i++){
			kv[i]=(mod-mod/i)*kv[mod%i]%mod;
		}
		long long as=1;
		int jk=1;
		for(int i=n;i>=1;i--){
			as*=i;
			as%=mod;
			as*=kv[jk];
			as%=mod;
			if(jk>=3){
				ans+=as;
				ans%=mod;
			}
			jk++;
		}
		cout<<ans;
	}
	return 0;
} 