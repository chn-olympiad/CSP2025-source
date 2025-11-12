#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gets() {
    int input = getchar();
    ll ret = 0, neg = 1;
    while(input < '0' || input > '9') {
        if(input == '-') {
            neg = -1;
        }
        input = getchar();
    }
    while(input >= '0' && input <= '9') {
        ret = input - '0' + ret * 10;
        input = getchar();
    }
    return ret * neg;
}
void puts(ll output) {
    if(output < 0) {
        putchar('-');
        output = - output;
    }
    if(output > 9) {
        puts(output / 10);
    }
    putchar(char(output % 10 + '0'));
}
map<array<vector<int>, 2>, int> mp;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i ++) {
        string a, b;
        cin >> a >> b;
        if(a == b) continue;
        vector<int> v, w;
        int len = a.length();
        int lt = 0, rt = len - 1;
        while(a[lt] == b[lt]) lt ++;
        while(a[rt] == b[rt]) rt --;
        for(int i = lt; i <= rt; i ++) {
            v.emplace_back(a[i] - 'a');
            w.emplace_back(b[i] - 'a');
        }
        mp[{v, w}] ++;
    }
    for(int i = 0; i < q; i ++) {
        string a, b;
        cin >> a >> b;
        vector<int> v, w;
        int lt = 0, rt = -1, len = a.length();
        for(int j = 0; j < len; j ++) {
            if(a[j] != b[j]) {
                if(rt == -1) {
                    v.emplace_back(a[j] - 'a');
                    w.emplace_back(b[j] - 'a');
                    lt = rt = j + 1;
                } else {
                    rt = j;
                    while(lt <= rt) {
                        v.emplace_back(a[lt] - 'a');
                        w.emplace_back(b[lt] - 'a');
                        lt ++;
                    }
                }
            }
        }
        cout << mp[{v, w}] << '\n';
    }
    return 0;
}
//g++ -g replace.cpp -o r -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=address,undefined
