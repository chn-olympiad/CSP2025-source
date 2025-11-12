//C 
#include<bits/stdc++.h>
using namespace std;
string s;
int n, m, c[505], ans;
bool vis[505];
void dfs(int st, int ys, int ws, int qsb){
	if(st == n + 1){
		if(ys >= m)ans++;
		return;
	}
	if(ys + ws < m)return;
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		vis[i] = 1;
//		printf("di%dge:choose:%d\n", st, i);
		if(s[st - 1] == '0' || c[i] <= qsb)dfs(st + 1, ys, ws - 1, qsb + 1);
		else dfs(st + 1, ys + 1, ws - 1, qsb);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	if(m == n){
		long long mul = 1;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0' || c[i] == 0){
				printf("0");
				return 0;
			}
			mul *= i;
			mul %= 998244353;
		}
		printf("%d", mul);
		return 0;
	}
	else dfs(1, 0, n, 0);
	printf("%d", ans);
	return 0;
}
//K
