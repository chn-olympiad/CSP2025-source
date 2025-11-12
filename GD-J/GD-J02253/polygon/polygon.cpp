#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n, a[5005], ans, cnt1;
bool visit[5005];

int mu(int k) {
	return k % 998 % 244 % 353;
}

void search(int tmp, int m, int cnt, int maxx) {
	cnt1++;
	if(cnt > maxx * 2 && m >= 3 ) {
		ans++;
		ans = mu(ans);
		//return ;
	}
	if(tmp >= n) return ;
	for(int i = 1; i <= n-tmp; i++) {
		int tmp1 = tmp + i;
		visit[tmp1] = 1;
		search(tmp1, m+1, cnt + a[tmp1], max(maxx, a[tmp1]));
		visit[tmp1] = 0;
	}
	return ;
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		visit[i] = 1;
		search(i, 1, a[i], a[i]);
		visit[i] = 0;
	}
	
	cout << ans << endl;
	return 0;
}

//5 2 2 3 8 10
