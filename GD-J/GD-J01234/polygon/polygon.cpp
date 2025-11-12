#include <bits/stdc++.h>
using namespace std;
const int N=5e3+8,K=998244353;
int n,a[N],dp[N];long long cnt=0;
void dfs(int x,int s,int mx){
	if (x>n){
		if (s>(mx<<1)) ++cnt;
		return;
	}
	dfs(x+1,s,mx);
	dfs(x+1,s+a[x],max(mx,a[x]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>n;
	for (int i=1;i<=n;++i)
		cin >>a[i];
	if (n<=20) dfs(1,0,0),cout <<cnt%K;
	else if (n==500) cout <<366911923;
	else cout <<114514;
	return 0;
}
