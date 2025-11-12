#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

const ll maxn = 15;

string str;
void Input() {
	cin >> str;
}

ll cnt[maxn];
void Init() {
	for (auto i : str) {
		if (i >= '0' && i <= '9') {
			++cnt[i - '0'];
		}
	}
}

void Print() {
	for (ll i = 9; i >= 0; --i) {
		for (ll j = 1; j <= cnt[i]; ++j) {
			printf("%lld", i);
		}
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	Input();
	Init();
	Print();
	return 0;
}