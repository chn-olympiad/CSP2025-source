#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
const long long mod=998244353;
void dfs(long long x,long long y){
	if(y>a[x-1]*2) ans=(ans+1)%mod;
	if(x>n){
		return;
	}
	dfs(x+1,y);dfs(x+1,y+a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
