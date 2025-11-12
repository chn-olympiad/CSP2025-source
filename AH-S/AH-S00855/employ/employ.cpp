#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],ls[505],f[5005];
long long ret = 0;
void dfs(int step){
	if(step == n){
		int sum = 0,ans = 0;
		for(int i = 1;i<=n;i++){
			if(sum>=ls[i]){
				continue;
			}
			if(s[i-1] == '0'){
				sum++;
				continue;
			}
			else{
				ans++;
			}
		}
		if(ans >= m){
			ret++;
			ret%=998244353;
		}
		return ;
	}
	for(int i = 1;i<=n;i++){
		if(!f[i]){
			f[i] = 1;
			step++;
			ls[step] = a[i];
			dfs(step);
			step--;
			f[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	dfs(0);
	cout << ret;
	return 0;
}
