#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int a[N];
int n,ans;
void dfs(int idx,int sum,int mx,int op,int k){
	if(idx>n) return ;
	if(op==1){
		sum+=a[idx]; mx=max(mx,a[idx]);
		if(k>=3&&sum>2*mx) ans++,ans%=mod;
	}	
	dfs(idx+1,sum,mx,1,k+1);
	dfs(idx+1,sum,mx,0,k);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,1,1);
	dfs(1,0,0,0,0);
	cout<<ans%mod<<"\n";
	return 0;
}
