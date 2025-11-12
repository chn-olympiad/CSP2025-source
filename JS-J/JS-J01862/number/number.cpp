#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 5;
string s;
int k, a[N];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a[k] = s[i] - '0';
            k ++;
        }
    }
    sort(a, a + k, cmp);
    for(int i = 0; i < k; i ++) cout << a[i];
    return 0;
}
