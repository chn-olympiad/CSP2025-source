#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5100],dp[5100],vis[5100],ant;
bool check(int x){
	long long sum=0,ma=0;
	for(int i=1;i<=x;i++){
		sum+=dp[i];
		ma=max(ma,dp[i]);
	}
	if(sum>ma*2){
		return true;
	}else{
		return false;
	}
}
void dfs(int id,int s){
	if(id==n+1){
		if(check(id-1)){
			ant++;
		}
		return;
	
	}
	if(id>=4){
		if(check(id-1)){
			ant++;
		}
	}
	for(int i=s+1;i<=n;i++){
		if(vis[i]==1)continue;
		dp[id]=a[i];
		vis[i]=1;
		dfs(id+1,i);
		dp[id]=0;
		vis[i]=0;
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long N=998244353;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ant%N;
	return 0;
}
