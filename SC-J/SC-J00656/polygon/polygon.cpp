#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long mod=998244353;
int n,a[5005];
int ans=0;
void dfs(int i,int sum,int maxn,int cnt){
	if(sum>maxn*2 && cnt>=3){
		ans++;
		ans%=mod;
	}
	for(int j=i+1;j<=n;j++){
		dfs(j,sum+a[j],max(maxn,a[j]),cnt+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],0,1);
	}
	cout<<ans%mod;
	return 0;
} 