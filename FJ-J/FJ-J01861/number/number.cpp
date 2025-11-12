#include <bits/stdc++.h>
//#define fc freopen("a.in", "r", stdin)

using namespace std;
const int N = 15;

//inline int read(char ch = getchar(), int x = 0, int f = 1) {
//	for (; ch < '0' || ch > '9'; ch = getchar())
//		if (ch == '-') f = -1;
//	for (; ch >= '0' && ch <= '9'; ch = getchar())
//		x = x * 10 + ch - '0';
//	return x * f;
//}


int ton[N];
 
inline void SeaWave() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] >= '0' && s[i] <= '9')
			++ton[s[i] - '0'];	
//	for (int i = 0; i <= 9; ++i)
//		cout << ton[i] << ' ';
//	
	for (int i = 9; i >= 0; --i)
		while (ton[i]--) cout << i;
	return ;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--)
		SeaWave();
	return 0;
}
