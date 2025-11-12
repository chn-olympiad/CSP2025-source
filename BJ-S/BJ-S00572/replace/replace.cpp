#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, q, ans = 0;
map<string, string> m;

bool check(string a, string b){
    if(a == b) return true;
    return false;
}

string substring(string a, int i, int j){
    string ans = "";
    for(int k = i;k + i < j;k++){
        ans += a[k];
    }
    return ans;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        string x, y;
        cin >> x >> y;
        m[x] = y;
    }
    while(q--){
        ans = 0;
        string a, b;
        cin >> a >> b;
        if(a.size() != b.size()){
            cout << 0 <<'\n';
            break;
        }
        string ab = a;
        if(a == b) ans++;
        for(int i = 0;i < n;i++){
            for(auto it : m){
                if(substring(a, i, it.second.size()) == it.first){
                    for(int j = i;j + i < it.second.size();j++) a[j] = it.second[j];
                    if(a == b) ans++;
                    a = ab;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
