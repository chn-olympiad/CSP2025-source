#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
bool nandu[510];
int c[510];
bool vis[510];
int cnt = 0;
void search(int t, int ok){
	if (t == n){
		if (ok >= m)cnt++;
		cnt %= 998244353;
		return;
	}
	int zou = t - ok;
	for (int i = 0; i < n; i++){
		if (vis[i])continue;
		vis[i] = true;
		if (zou >= c[i])search(t + 1, ok);
		else search(t + 1, ok + nandu[t]);
		vis[i] = false;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		char a;
		cin >> a;
		nandu[i] = a - '0';
	}
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	search(0, 0);
	cout << cnt;
	return 0;
} 
