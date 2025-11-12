#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;
using LL = long long;
const int N = 1e5 + 5;
int n, q;
string s1[N], s2[N];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i];
    while (q -- ){
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()){
            puts("0");
            continue;
        }
        int res = 0;
        for (int i = 1; i <= n; i ++ ){
            int pos = t1.find(s1[i]);
            if (!~pos) continue;
            string backup = t1;
            t1.replace(pos, s2[i].size(), s2[i]);
            if (t1 == t2) res ++ ;
            t1 = backup;
        }
        cout << res << endl;
    }
    return 0;
}
