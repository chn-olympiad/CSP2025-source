#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans=0;
void dfs(long long sum,long long ma,long long k){
	if(k>n){
		ans+=(sum>ma*2);
		return;
	}else{
		dfs(sum+a[k],max(ma,a[k]),k+1);
		dfs(sum,ma,k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
