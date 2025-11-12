#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
vector<int> cnt;
string s;
bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    n = s.length();
    for(int i = 0;i < n;i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            cnt.push_back(s[i] - '0');
        }
    }
    sort(cnt.begin(), cnt.end(), cmp);
    if(cnt[0] > 0) {
        for(int i = 0;i < cnt.size();i ++) {
            cout << cnt[i];
        }
    }else {
        cout << 0;
    }
    return 0;
}
