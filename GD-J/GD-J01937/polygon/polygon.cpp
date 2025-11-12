#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3;
const int mod=998244353;
int a[maxn],ans,max_all;
int n;
void dfs(int x,int maxx,int sum){
	if(x==n+1){
		if(sum>maxx*2) ans++;
		ans%=mod;
		return ;
	}
	dfs(x+1,maxx,sum);
	int akcsp=maxx;
	maxx=max(a[x],maxx);
	sum+=a[x];
	dfs(x+1,maxx,sum);
	maxx=akcsp;
	sum-=a[x];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		max_all=max(max_all,a[i]);
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
/*
hope pts:10*4=40
*/
/*
4
1 1 1 0
*/ 
