#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, inf = 0x3f3f3f3f;
int a[10], n;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.length();
	f(i, 0, n){
		if (s[i] >= 48 && s[i] <= 57) a[s[i] - 48]++;
	}
	int a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3], a4 = a[4], a5 = a[5], a6 = a[6], a7 = a[7], a8 = a[8], a9 = a[9];
	f(i, 0, a9) cout << 9;
	f(i, 0, a8) cout << 8;
	f(i, 0, a7) cout << 7;
	f(i, 0, a6) cout << 6;
	f(i, 0, a5) cout << 5;
	f(i, 0, a4) cout << 4;
	f(i, 0, a3) cout << 3;
	f(i, 0, a2) cout << 2;
	f(i, 0, a1) cout << 1;
	f(i, 0, a0) cout << 0;
	return 0;
}
