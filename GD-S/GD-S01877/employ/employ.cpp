#include<bits/stdc++.h>
#define int long long
#define fo(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int N = 5e2 + 5, Mod = 998244353;

int n, m;
int c[N];

char s[N];

int vis[N], arr[N], ans;

int check() {
	int cnt = 0;
	
	int fail = 0;
	fo(i, 1, n) {
		if(s[i] == '0')
			fail ++;
		else if(s[i] == '1') {
			if(fail >= c[arr[i]]) {
				fail ++;
				continue;
			}
			cnt ++;
		}
	}
	cout << cnt << ":\n";
	return cnt >= m;
}

inline void dfs(int cur) {
	if(cur > n) {
		if(check())
			++ ans;
//		else {
//			fo(i, 1, n) {
//				cout << c[arr[i]] << " ";
//			}
//			cout << "\n";
//		}
		return;
	}
	fo(i, 1, n) {
		if(vis[i])
			continue;
		vis[i] = 1;
		arr[cur] = i;
		dfs(cur + 1);
		vis[i] = 0;
	} 
}
signed main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	//all exp
	cin >> s + 1;
	
	int subA = 1;
	fo(i, 1, n) {
		if(s[i] != '1') {
			subA = 0;
			break;
		}
	}
	
	fo(i, 1, n)
	cin >> c[i];
	
//	if(subA) {
////		cout << "!!!!\n";
//		int fc = 1;
//		fo(i, 1, n) 
//			fc = fc * i % Mod;
//		cout << fc << "\n";
////		return 0;
//	}
	
	dfs(1);
	cout << ans << "\n";
	
	return 0;
}
