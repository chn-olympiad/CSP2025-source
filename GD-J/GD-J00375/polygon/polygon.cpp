#include <bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;

int n,ans;
int a[N];

void dfs(int x,int ks,int km){
	if(x==n+1){
		if(ks>2*km) ans=(ans+1)%MOD;
		return;
	}
	dfs(x+1,ks+a[x],max(km,a[x]));
	dfs(x+1,ks,km);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=50) dfs(1,0,0);
	cout<<ans%MOD;
	
	return 0;
}
