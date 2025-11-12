#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],vis[500005],ans;
void dfs(int sum,int maxn){
	if(sum>(maxn*2)){
		ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(sum+a[i],max(maxn,a[i]));
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vis[1]=1;
	vis[2]=1;
	vis[3]=1;
	dfs(a[1]+a[2]+a[3],max(a[1],max(a[2],a[3])));
	cout<<ans;
	return 0;
}  