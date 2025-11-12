#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, q;
string s1[N], s2[N], a1, a2;
int ans[N];

void f(){
    for (int i = 1; i <= q; i ++){
        string s = s1[i];
        int idx = 0;
        //cout << i << endl;
        for (int j = 0; j < s.size(); j ++){
            //cout << idx;
            if (s[j] == a1[idx]){
                if (a2.size()-1 >= idx) s[j] = a2[idx];
                idx ++;
            }
            else if (s[j] != a1[idx] && idx != 0){
                idx = 0;
                s = s1[i];
            }
            if (idx == a1.size()){
                if (s == s2[i]) ans[i] ++;
                s = s1[i];
                j = j - idx+2;
                idx = 0;
            }
        }
        //cout << endl;
    }
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= q; i ++){
        cin >> s1[i] >> s2[i];
    }
    for (int i = 1; i <= n; i ++){
        cin >> a1 >> a2;
        f();
    }
    for (int i = 1; i <= q; i ++){
        cout << ans[i] << '\n';
    }
    return 0;
}
