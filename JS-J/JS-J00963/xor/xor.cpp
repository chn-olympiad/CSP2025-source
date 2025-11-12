#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long ans=0;
int dfs(int cnt,long long sum,long long y1){
	if(cnt==n){
		ans=max(ans,sum);
	}
	else{
		long long y=y1^a[cnt];
		if(k==y){
			dfs(cnt+1,sum+1,0);
		}
		else{
			dfs(cnt+1,sum,y1^a[cnt]);
		}
		dfs(cnt+1,sum,0);
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	return 0;
}
