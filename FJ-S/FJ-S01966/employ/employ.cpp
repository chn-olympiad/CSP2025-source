#include<bits/stdc++.h>
#define ll long long
#define N 510
using namespace std;
ll n,m,ans;
char s[N];
ll c[N];
bool v[N];
ll p=998244353;
void dfs(ll zz,ll jr) {
	if(n-jr<m) return ;
	if(zz>n) {
		if(n-jr>=m)
			ans++;
		return ;
	}
	for(ll i=1; i<=n; i++) {
		if(v[i]) continue;
		v[i]=true;
		if((s[i]=='0')||(c[i]<=jr)) dfs(zz+1,jr+1);
		else dfs(zz+1,jr);
		v[i]=false;
	}
	return ;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n; i++)
		cin>>s[i];
	for(ll i=1; i<=m; i++)
		cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/