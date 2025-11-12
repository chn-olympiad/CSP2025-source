// oh oh oh
// great T1
#include <iostream>
using namespace std;
string s;
int tmp[100];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(char x : s) {
        if('0' <= x && x <= '9') {
            tmp[x - '0']++;
        }
    }
    for(int i = 9; i >= 0; i--)
        while(tmp[i]--)
            cout << i;
    cout << "\n";
    return 0;
}