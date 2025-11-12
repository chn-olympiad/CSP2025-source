#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,ans=0,a[5005];
void dfs(long long s,long long gs,long long sum,long long max_num){
	if(s>n){
		if(gs>=3){
			if(sum>2*max_num) ans=(ans+1)%mod;
		}
		return;
	}
	dfs(s+1,gs+1,sum+a[s],max(max_num,a[s]));
	dfs(s+1,gs,sum,max_num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}