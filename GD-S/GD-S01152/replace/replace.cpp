#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, q, cnt;
string a1[maxn][2], s1, s2;
int ni(string a, string b){
	int l1 = a.size(), l2 = b.size();
	for(int i = 0;i + l1 - 1 < l2;i++){
		bool flag = false;
		for(int j = 0;j < l1;j++){
			if(a[j] != b[i+j]) flag = true;
		}
		if(flag) continue;
		return i;
	}
	return -1;
}
void dfs(int x, string y){
	if(x > n){
		if(y == s2) cnt++;
		return;
	}
	int st;
	if((st = ni(a1[x][1], y)) != -1){
		dfs(x + 1, y);
		int l = a1[x][1].length();
		for(int i = 0;i < l;i++){
			y[st+i] = a1[x][1][i];
		}
		dfs(x + 1, y);
	}else dfs(x + 1, y);
	return;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a1[i][1] >> a1[i][2];
    for(int i = 1;i <= q;i++){
		cnt = 0;
		cin >> s1 >> s2;
		if(s1.length() != s2.length()){
			cout << "0\n";
			continue;
		}
		dfs(1, s1);
		cout << cnt << "\n";
	}
	return 0;
}

