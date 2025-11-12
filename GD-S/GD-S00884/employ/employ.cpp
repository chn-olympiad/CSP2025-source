#include<bits/stdc++.h>
using namespace std;

int n, m, x, y, a[501], sum, b[501];
char s[510];
bool ok[501];

void dfs(int i){
	if(i == n + 1){
		int ans = 0, res = 0;
		for(int j = 1; j <= n; j++)
			if(s[j] == '0' || b[j] <= ans)
				ans++;
			else
				res++;
		if(res >= m)
			sum = (sum + 1) %  998244353;
		return;
	}
	for(int j = 1; j <= n; j++){
		if(!ok[j]){
			b[i] = a[j];
			ok[j] = true;
			dfs(i + 1);
			ok[j] = false;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; i++){
		if(s[i] == '0')
			x++;
		else
			y++;
		scanf("%d", &a[i]);
	}
	dfs(1);
	printf("%d\n", sum);
	return 0;
}
