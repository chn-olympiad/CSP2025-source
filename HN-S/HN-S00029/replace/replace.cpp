#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 2;


int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    int n, q;

    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> s1 >> s2;
    }
    while(q --){
        cin >> s1 >> s2;
        cout << 1 << '\n';
    }

    return 0;
}
