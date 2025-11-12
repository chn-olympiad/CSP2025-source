#include<bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int ans = 0,n,m,c[510];
char s[510];

void dfs(int i,int cnt,int me){
	if(i == n+1){
		if(cnt >= m){
			ans++;
			ans%= Mod;
		}
		return;
	}
	if(cnt+n-i < m) return;
	if(me <= c[i]){
		me++;
		dfs(i+1,cnt,me);
		return;
	}
	me++;
	dfs(i+1,cnt,me);
	me--;
	cnt++;
	dfs(i+1,cnt,me);
	cnt--;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	scanf("%s",s+1);
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
