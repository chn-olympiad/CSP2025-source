#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string str;
int a[N], s;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> str;
    for (int i = 0;i < str.size();i ++){
        if ('9' >= str[i] && str[i] >= '0'){
            a[++s] = str[i] - '0';
        }
    }
    sort(a + 1, a + 1 + s);
    for (int i = s;i >= 1;i --) cout << a[i];
    return 0;
}
/*
2 2
98 99 100 97

*/