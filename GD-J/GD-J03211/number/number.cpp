#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
//#define LOCAL

using namespace std;

int main() {
    #ifndef LOCAL
        freopen("number.in", "r", stdin);
        freopen("number.out", "w", stdout);
    #endif // LOCAL

    string s;
    cin >> s;

    string ans = "";

    for (const auto& c : s)
        if (c >= '0' && c <= '9')
            ans += c;

    sort(ans.begin(), ans.end(), greater <char> ());

    cout << ans;

    #ifndef LOCAL
        fclose(stdin);
        fclose(stdout);
    #endif // LOCAL

    return 0;
}
