#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long double wisdom;

int main() {
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	string S, T = ""; cin >> S; for (char x : S) if ('0' <= x && x <= '9') T += x;
	sort(T.begin(), T.end(), greater <char>()), cout << T;
	return 0;
}
