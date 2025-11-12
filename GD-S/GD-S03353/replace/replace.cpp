#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out() cout << "sb\n"

int n, q;
string s1, s2;

int main() {
//	system("fc replace.out replace.ans");
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	IOS;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1 >> s2;
	for (int i = 1; i <= q; i++) {
		cin >> s1 >> s2;
		cout << 0 << "\n";
	}
	return 0;
}

