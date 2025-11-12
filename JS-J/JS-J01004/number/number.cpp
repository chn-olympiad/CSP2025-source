#include <bits/stdc++.h>
using namespace std;

string s;
int j = 1;
char s1[1145140];
bool cmp(char a, char b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            s1[j] = s[i];
            j++;
        }
    }
    sort(s1 + 1, s1 + j + 1, cmp);
    for (int i = 1; i <= j; i++) {
        if (isdigit(s1[i])) {
            cout << s1[i];
        }
    }
	return 0;
}
