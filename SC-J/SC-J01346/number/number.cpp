#include<bits/stdc++.h>
using namespace std;

void setup() {
    freopen("number.in", "r", stdin);
    freopen("number.out","w",stdout);
}
vector<int> p(11);
int main() {
	setup();
    string s;
    cin >> s;
    for (int i = 0;i < s.size(); i++){
        if ('0'<= s[i] && s[i] <= '9') {
            p[s[i] - '0'] ++;
        }
    }
    for (int i = 9;i >= 0; i--) {
        for (int j = 0;j < p[i]; j++) {
            cout << i;
        }
    }
    cout << "\n";
    return 0;
}