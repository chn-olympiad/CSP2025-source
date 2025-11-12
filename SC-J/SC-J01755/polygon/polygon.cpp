#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[5005];
int n;
int ans=0;
void dfs(int u,int mx,int res,int num){
	if(u>n){
		if(res>mx*2 && num>=3) ans++;
		if(ans>=mod) ans-=mod;
		return ;
	}
	dfs(u+1,max(mx,a[u]),res+a[u],num+1);
	dfs(u+1,mx,res,num); 
}
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool f=1;  
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}

	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0; 
} 