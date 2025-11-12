# include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    int book[1000001];
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if(s[i] >= '0' && s[i] <= '9')
            book[s[i] - '0']++;
    }
    for(int i = 9;i >= 0;i--) {
        if(book[i] != 0) {
            for(int j = 1;j <= book[i];j++)
                cout << i;
        }

    }
    return 0;
}
