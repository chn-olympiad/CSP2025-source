#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int r[s.length()], n = 0;
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            r[n++] = s[i] - '0';
        }
    }
    sort(r, r + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << r[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
