#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, q, ans;
string s[maxn], s2[maxn], t1, t2;
void chag(string x, string y){
    string t1, t2;
    for(int i = 1; i <= n; i++){
        if(0 <= x.find(s[i]) && x.find(s[i]) < x.size() && 0 <= y.find(s2[i]) && y.find(s2[i]) < y.size()){
            t1 = t2 = "";
            for(int j = 0; j < x.size(); j++){
                if(x[j] != y[j]) t1 += x[j], t2 += y[j];
            }
            if(t1 == s[i] && t2 == s2[i] && s[i].size() != x.size()) ans++;
            else if(s[i] == x && y == s2[i]) ans++;
        }
    }
}
int main(){
    freopen("replace.in","r", stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s[i] >> s2[i];
    while(q--){
        ans = 0;
        cin >> t1 >> t2;
        chag(t1, t2);
        cout << ans << '\n';
    }
    return 0;
}