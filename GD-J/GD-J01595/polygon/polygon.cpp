#include <bits/stdc++.h>
using namespace std;
long long ans=0;
long long n;
int a[50005];
int vis[50005];
bool check(int maxn,int sum){
	if(sum>2*maxn){
		return true;
	}else{
		return false;
	}
}
void dfs(int x,int k,int maxn,int sum){
	if(x==n+1&&k>=3){
		if(check(maxn,sum)){
			ans++;
		}
		return;
	}else if(x==n+1){
		return;
	} 
	int y=max(maxn,a[x]);
	vis[x]=1;
	dfs(x+1,k+1,y,sum+a[x]);
	vis[x]=0;
	dfs(x+1,k,maxn,sum);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	long long ans1=ans%998244353;
	cout<<ans1;
	return 0;
}
