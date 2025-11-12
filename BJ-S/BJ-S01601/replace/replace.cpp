#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string s1[N], s2[N];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
    while(q--){
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for (int i = 1;i <= n;i++){
            int t = t1.find(s1[i]);
            if (t == -1) continue;
            string temp = t1.substr(0, t) + s2[i] + t1.substr(t + s1[i].size());
            //cout << temp << " ";
            if (temp == t2) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}