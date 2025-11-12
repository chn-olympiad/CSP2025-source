#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[205],cnt;
bool flag=1;
void dfs(int pos,int sum,int maxn,int m){
	if(pos>n){
		if(sum>2*maxn&&m>=3){
			cnt++;
			cnt%=mod;
		}return;
	}
	dfs(pos+1,sum%mod,maxn,m);
	dfs(pos+1,sum%mod+a[pos]%mod,max(maxn,a[pos]),m+1);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag){
		int ans=0,k=3;
		while(n>=k){
			ans+=k*(n-k+1)%mod;
			ans%=mod;
			k++;
		}cout<<ans%mod;
	}else{
		dfs(1,0,0,0);
		cout<<cnt%mod;
	}

	return 0;
}
