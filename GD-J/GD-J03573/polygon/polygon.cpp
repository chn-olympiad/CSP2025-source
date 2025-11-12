#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
void dfs(int t,int ma,int sum){
	if(t==n+1){
		if(sum>ma*2){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	dfs(t+1,ma,sum);
	dfs(t+1,max(ma,a[t]),sum+a[t]); 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,a[1],0);
	cout<<ans;
	return 0;
}
