#include<bits/stdc++.h>

using namespace std;

const int N = 5005,mod = 998244353;
int n;
int a[N],vis[N];
int ans;
void dfs(int id,int cnt,int sum,int maxs){// id cnt sum
	if(cnt>=3 && sum>maxs*2) ans++,ans%=mod;
	if(id>n) return;
	for(int i = id;i<=n;i++){
		if(vis[i]==0){
			vis[i] = 1;
			dfs(i,cnt+1,sum+a[i],max(maxs,a[i]));
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans%mod;
	
	return 0;
}
