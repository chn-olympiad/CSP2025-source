#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out cout << "sb\n";

int cnt[100];
string s;

int main() {
//	system("fc number.out number4.ans");
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	IOS;
	cin >> s;
	for (char &ch : s) {
		if (ch >= '0' && ch <= '9') cnt[ch - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i]) {
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}

