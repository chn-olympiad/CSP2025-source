#include <iostream>
#include <algorithm>

using namespace std;

string s;

bool cmp(int x, int y) {
	return x > y;
}

int p[1000005], cnt;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') p[++cnt] = s[i] - '0';
	}
	sort(p + 1, p + cnt + 1, cmp);
	if(p[1] == 0) cout << 0;
	else {
		for(int i = 1; i <= cnt; i++) printf("%d", p[i]);
	}
}
