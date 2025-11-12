#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5010];
long long dfs(long long id,long long m,long long tot,long long mx){
	if(id==n+1)return m>=3&&mx*2<tot;
	return (dfs(id+1,m+1,tot+a[id],max(mx,a[id]))+dfs(id+1,m,tot,mx))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		cout<<dfs(1,0,0,0);
	}
	else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=mod;
		}
		cout<<(ans-1-n-n*(n-1)/2+mod)%mod;
	}
	return 0;
}

