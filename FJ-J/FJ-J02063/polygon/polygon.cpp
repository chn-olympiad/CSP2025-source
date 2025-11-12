#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int MOD=998244353;
const int N=5000+5;
int n,a[5005];
ll ans=0;
bool T=true;
void dfs(int pos,ll sum,int last,int cnt) {
	if(pos==n+1) {
		if(sum>2*a[last]&&cnt>=3)ans++;
		if(ans>=MOD)ans-=MOD;
		return;
	}
	dfs(pos+1,sum+a[pos],pos,cnt+1);
	dfs(pos+1,sum,last,cnt);
}
void solve1() {
	dfs(1,0,0,0);
	cout<<ans;
	exit(0);
}
ll f[505][5005];
ll Dfs(int pos,ll sum,int cnt) {
	if(f[pos][sum])return f[pos][sum];
	if(pos==n)return 0;
	ll res=0;
	if(sum>a[pos+1]&&cnt==2&&pos!=n)res++;
	res=(res+Dfs(pos+1,sum+a[pos+1],min(cnt+1,2)))%MOD;
	res=(res+Dfs(pos+1,sum,cnt))%MOD;
	return f[pos][sum]=res;
}
void solve2() {
	cout<<Dfs(0,0,0);
	exit(0);
}
void solveT() {
	ll ans=0;
	ll res=1;
	for(int i=1; i<=n; i++) {
		res*=2;
		if(res>=MOD)res-=MOD;
	}
	ans=res-n-n*(n-1)/2-1;
	cout<<ans;
	exit(0);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)T=false;
	}
	sort(a+1,a+n+1);
	if(T)solveT();
	else if(n<=25)solve1();
	else solve2();
	return 0;
}
