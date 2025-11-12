#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int a[N];

bool cmp(int ax, int ay) {
	return ax > ay;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	memset(a, 0, sizeof(a));
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i=0; i<s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[cnt++] = s[i] - '0';
		}
	}
	sort(a, a+cnt, cmp);
	for(int i=0; i<cnt; i++) cout << a[i];
	return 0;
} 
