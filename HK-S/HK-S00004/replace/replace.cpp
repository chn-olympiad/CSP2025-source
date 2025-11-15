#include <bits/stdc++.h>
using namespace std;
#define tendoualice
#ifdef tendoualice
ifstream input("replace.in");
ofstream output("replace.out");
#define cin input
#define cout output
#endif

#define ll long long

unordered_map<string, string> m;

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        m[a] = b;
    }

    while(q--){
        int cnt = 0;
        string t1, t2;
        cin >> t1 >> t2;
        int len = t1.length();
        for(int i = 0; i < len; i++){
            for(int j = 1; j <= len - i; j++){
                string t1l = t1.substr(0, i);
                string t1mid = t1.substr(i, j);
                string t2l = t2.substr(0, i);
                string t2mid = t2.substr(i, j);
                string t1r = "", t2r = ""; 
                if(i + j != len) t1r = t1.substr(i + j), t2r = t2.substr(i + j);
                if(t1l == t2l and t1r == t2r and m[t1mid] == t2mid) cnt++;
            }
        }
        cout << cnt << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
// g++ -O2 -std=c++14 -static replace.cpp -o replace

// 4 2 xabcx xadex ab cd bc de aa bb xabcx xadex aaaa bbbb
// 4 1 xabcx xadex ab cd bc de aa bb aaaa bbbb 