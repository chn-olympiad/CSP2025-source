#include<bits/stdc++.h>
using namespace std;
int n, a[5005], te, ans;
int used[5005];
bool cmp(int x, int y){
	return x > y;
}

void dfs(int edgs, int nber, int k, int tot){
	if(nber > edgs){
		if(tot > te)	ans++;
		return;
	}
	for(int i = k; i <= n; i++){
		if(used[i] == 0 && a[i] < te){
			used[i] = 1;
			dfs(edgs, nber + 1, i + 1, tot + a[i]);
			used[i] = 0;
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		te = a[i];
		for(int j = 2; j <= n - 1; j++){
			memset(used, 0, sizeof(used));
			used[i] = 1;
			dfs(j, 1, 1, 0);
		}
	}
	cout << ans;
}
