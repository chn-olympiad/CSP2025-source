#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string S; cin >> S;
	int n = S.size();

	string T;
	for (int i = 0; i < n; i++) 
        if (isdigit(S[i])) T.push_back(S[i]);
    sort(T.begin(), T.end(), greater<char>());
    cout << T;

	return 0;
}
