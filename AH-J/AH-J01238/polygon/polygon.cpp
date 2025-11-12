#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans;
void dfs(int s,long long sum,long long mx,int cho){
	if(s==n){
		if(sum>2*mx&&cho>=3)ans=(ans+1)%mod;
		return;
	}
	dfs(s+1,sum+a[s+1],max(mx,a[s+1]),cho+1);
	dfs(s+1,sum,mx,cho);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans<<"\n";
	return 0;
}
