#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s1[N], s2[N], t1[N], t2[N];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >> q;
    for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    for(int i = 1; i <= q; i++){
        cin >> t1[i] >> t2[i];
        int len = t1[i].size();
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            int len2 = s1[j].size();
            for(int k = 0; k <= len - len2; k++){
                string st0 = t1[i].substr(k, len2);
                if(st0 != s1[j]) continue;
                string st = t1[i].substr(0, k) + s2[j] + t1[i].substr(k + len2);
                if(st == t2[i]){
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt <<endl;
    }
}
