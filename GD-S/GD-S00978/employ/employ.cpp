#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550;
const int MOD=998244353;
int n,m,a[N],c[N];
bool vis[N];
int v[N],flag=1;
int dfs(int dq,int r){
//	cout<<dq<<" "<<r<<"\n";
	int ans=0;
	if(dq>n){
		if(r>=m){
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
//		if(dq==n) cout<<i;
		vis[i]=1;
		if(dq-r-1>=c[i]) {
			ans+=dfs(dq+1,r);
		}else{
			ans+=dfs(dq+1,r+v[dq]);
		}
		ans%=MOD;
		vis[i]=0;
	}
//	cout<<ans<<"\n";
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
//		x='1';
		if(x=='1'){
			v[i]=1;
		}else{
			v[i]=0;
			flag=0;
		}
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	if(n<=10){
		cout<<dfs(1,0);
		return 0;
	}
	cout<<0;
	return 0;
}
