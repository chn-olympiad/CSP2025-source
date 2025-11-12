#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int mod=998244353;
int a[5010];
int n;
int ans=0;
void dfs(int x,int mx,int m,int sum){
	if(m==n+1)return;
	if(m>=3&&sum>mx*2){
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,max(mx,a[i]),m+1,sum+a[i]);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],1,a[i]);
	}
	cout<<ans;
} 
