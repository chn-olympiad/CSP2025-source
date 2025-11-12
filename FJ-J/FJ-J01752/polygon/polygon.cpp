#include<bits/stdc++.h>
using namespace std;

int n, a[5005], w, cnt = 0;
int l[5005];

void dfs(int f, int q){
	if(f == w){
		int maxn = 0, sum = 0;
		for(int i = 1; i <= f; i++){
			maxn = max(a[l[i]], maxn);
			sum += a[l[i]];
		}
		if(sum > maxn * 2){
			cnt++;
			cnt %= 998244353;
		}
		return;
	}
	for(int i = q; i <= n; i++){
		l[f + 1] = i;
		f++;
		dfs(f, i + 1);
		f--;
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 3; i <= n; i++){
		w = i;
		dfs(0, 1);
	}
	cout << cnt;
	return 0;
}
