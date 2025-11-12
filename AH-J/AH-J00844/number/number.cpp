#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N];

string s;
int cnt;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    cin >> s;

    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i])) a[++cnt] = (s[i] - '0');
    }

    sort(a + 1, a + cnt + 1, greater<int>());

    for (int i = 1; i <= cnt; i++) cout << a[i];
    cout << '\n';
    return 0;
}