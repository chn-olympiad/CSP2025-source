#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, ans = 0;
string s1, s2, x[N], y[N];
void solve(string t){
    for(int i = 0; i < t.size(); i++){
        string nt = "";
        for(int j = i; j < t.size(); j++){
            nt += t[j];
            for(int k = 1; k <= n; k++){
                if(x[k] == nt){
                    string nw = y[k];
                    string newt = t;
                    newt.erase(i, j - i + 1);
                    newt.insert(i, nw);
                    if(newt == s2){
                        ans++;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= q; i++){
        cin >> s1 >> s2;
        ans = 0;
        solve(s1);
        cout << ans << "\n";
    }
    return 0;
}
