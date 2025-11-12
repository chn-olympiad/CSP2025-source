#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
int a[5005];
long long ans;
void dfs(int x,long long sum,long long maxx,int t){
	if(x==n+1){
		if(sum>2*maxx&&t>=3)
			ans++;
		ans%=mod;
		return;
	}dfs(x+1,sum+a[x],max(maxx,a[x]),t+1);
	dfs(x+1,sum,maxx,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}dfs(1,0,0,0);
	cout<<ans;
	
	return 0;
}
