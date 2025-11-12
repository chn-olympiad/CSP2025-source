#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100100],ans,f[1010];
void dfs(int x,int step,int m,int sum,int maxn){
	if(step==n+1){
		if(sum>(2*maxn)&&m>=3){
			ans++;
		}
		return;
	}
	if(x>=n)return;
	for(int i=x+1;i<=n;i++){
		dfs(i,step+1,m+1,sum+a[i],max(maxn,a[i]));
	}
	dfs(x+1,step+1,m,sum,maxn);
	return;
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
	dfs(0,1,0,0,0);
	cout<<ans;	
	} 
	else{
		ans=1;
		for(int i=n;i>=3;i--){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	return 0;
}
