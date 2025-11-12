#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
#define int long long
int n,a[N],ans;
void dfs(int sum,int k){
	if(k==n) return ;
	for(int i=k+1;i<=n;i++){
		if(sum>a[i]) ans++,ans%=mod;
		dfs(sum+a[i],i);
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];	
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
	return 0;
}
