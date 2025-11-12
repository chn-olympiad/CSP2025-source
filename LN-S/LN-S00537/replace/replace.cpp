#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5, MAXL = 5e6 + 5;
#define ll long long

string s1[MAXN], s2[MAXN];
int n, q;

bool check(string &a, string &b){
    for(int i = 0; i < (int)a.length(); i++){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> s1[i] >> s2[i];
    }
    string t1, t2, tmp;
    ll ans;
    while(q--){
        ans = 0;
        cin >> t1 >> t2;
        tmp = t1;
        if(t1.length() != t2.length()) {cout << 0; continue;}
        for(int k = 0; k < n; k++){//ite s
            for(int i = 0; i <= (int)t1.length() - (int)s1[k].length(); i++){
                if(check(s1[k], t1)){
                    for(int j = 0; j < (int)s1[k].length(); j++){
                        tmp[i + j] = s2[k][j];
                    }
                    if(check(tmp, t2)){
                        ans++;
                    }
                    for(int j = 0; j < (int)s1[k].length(); j++){
                        tmp[i + j] = t1[j];
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}