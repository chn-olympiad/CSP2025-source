#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,a[5005];
void dfs(int step,int cnt,int maxn,int sum){
	//枚举每个点是否选取，O(2^n)，40分 
	if(step>n){
		if(sum>maxn*2&&cnt>=3){
			ans=(ans+1)%mod; 
		}
		return;
	}
	dfs(step+1,cnt,maxn,sum);
	dfs(step+1,cnt+1,max(maxn,a[step]),sum+a[step]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
