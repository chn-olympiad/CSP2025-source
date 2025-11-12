#include<bits/stdc++.h>
#define N 1234
using namespace std;
int mod=998244353;
int sum ,a[N],vis[N],n;
int dfs(int b,int s){
	if(b==s){
		int maxn;
		for(int i=n;i>=1;i--){
			if(vis[i]){
				maxn=2*a[i];
				break;
			}
		}
		if(maxn<sum)return 1;
		return 0;
	}
	int res=0;
	for(int i=n;i>=1;i--){
		if(vis[i])break;
		vis[i]=1;
		sum+=a[i];
		res+=dfs(b,s+1)%mod;
		sum-=a[i];
		vis[i]=0;
		res=res%mod;
	}
	return res%mod;
}
int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=dfs(i,0)%mod;
		ans=ans%mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}