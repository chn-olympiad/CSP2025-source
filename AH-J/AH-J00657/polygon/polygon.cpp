#include<bits/stdc++.h>
using namespace std;
const int mod=99844353;
int n,a[5005];
bool vis[5005];
long long ans;
void dfs(int depth,int mx,int sum,int t) {
	if(depth==t+1) {
		if(sum>2*mx) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) {
			int m=mx;
			vis[i]=1,mx=max(mx,a[i]);
			dfs(depth+1,mx,sum+a[i],t);
			vis[i]=0,mx=m;
		}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) dfs(1,0,0,i);
	cout<<ans%mod;
	return 0;
}
