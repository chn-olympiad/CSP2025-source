#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], xo[500005];
long long ans = 0;
void dfs(int now_id, long long cnt){
	if(now_id > n){
		ans = max(cnt, ans);
		return;
	}
	for(int i = now_id; i <= n; i++){
		if((xo[i] ^ xo[now_id-1]) == k){
			dfs(i+1, cnt+1);
		}
	}
}
int main(){
	freopen("xor.in", " r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int flag1 = 1, flag01 = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		xo[i] = xo[i-1] ^ a[i];
		if(a[i] != 1)flag1 = 0;
		else if(a[i] != 1 && a[i] != 0) flag01 = 0;
	}
	if(flag1){
		cout << n/2;
		return 0;
	}else if(flag01){
		int cnt = 0;
		if(k == 0) {
			bool flag = 0;
			for(int i = 1; i <= n; i++){
				if(a[i]) flag = !flag;
				if(!flag) cnt++;
			}
		}else if(k == 1){
			for(int i = 1; i <= n; i++, cnt++){
				if(!a[i])cnt--;
			}
		}
		cout << cnt;
		return 0;
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}

