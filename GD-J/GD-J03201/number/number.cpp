#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 5;
using namespace std;

int a[N], cnt;

bool cmp(int x, int y){
	return x > y;
}

signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for(int i = 1; i <= n; i++){
		if(s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0';
	}
	sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++){
		cout << a[i];
	}
	return 0;
}
