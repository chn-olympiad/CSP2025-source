#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> ss;
bool cmp(string a, string b) {
    return a + b > b + a;
}
int main() {
		ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
    for (char c:s) {
        if (c >= '0' && c <= '9') {
			string temp;
			temp += c;
            ss.push_back(temp);
        }
    }
    sort(ss.begin(), ss.end(), cmp);
    for (auto x:ss) {
        cout << x;
    }
    return 0;
}
