#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int mod=998244353;
int c[maxn];
string s;
int n, m;
int ans;
int used[maxn];
int an[maxn];
void dfs(int depth, int before){
	if(depth==n+1){
		if(before+m==n){
			ans++;
			for(int j=1; j<=n; ++j) cout <<an[j] <<' ';
			cout <<'\n';
		}
		return ;
	}
	for(int i=1; i<=n; ++i){
		if(used[i]==0){
			used[i]=1;
			an[depth]=i;
			if(s[i]==0||before>=c[i]){
				dfs(depth+1, before+1);
			}
			else dfs(depth+1, before);
			used[i]=0;
			an[depth]=0;
		}
	} 
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n >>m;
	cin >>s;
	for(int i=1; i<=n; ++i) cin >>c[i];
	dfs(1, 0);
	cout <<ans%mod;
	return 0;
}
