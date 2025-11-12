#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s;
string ss = "";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            ss += s[i];
    }

    sort(ss.begin(), ss.end(), [](char a, char b) {
        return a > b;
    });

    cout << ss << "\n";

    cout << flush;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
