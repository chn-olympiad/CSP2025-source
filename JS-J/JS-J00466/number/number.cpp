#include <bits/stdc++.h>
using namespace std;

#define def auto
#define o4 inline

using ll = long long ;
using ull = unsigned long long ;
using uint = unsigned int ;
using cstr = const char *;

#define endl '\n';
constexpr ll N = 1e9;
constexpr ll inf = 0x3f3f3f3f;

struct IOFiles{
    cstr in, out;
};


o4 void init(IOFiles &file){
    cstr in = file.in, out = file.out;
    if (in != ""){
        freopen(in, "r", stdin);
        freopen(out, "w", stdout);
    }
    iostream::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
}

char a[N];
ll t;

IOFiles file{"number.in", "number.out"};
def solve(){
    string s; cin >> s;
    for(def c : s) {
        if (c >= '0' && c <= '9') {
            a[t++] = c;
            cout << (int)c << endl;
        }
    }
    sort(a, a+t);
    for(int i = 0;i < t;i ++){
        cout << a[t-i-1];
    }
    cout << endl;
}


int main(){
    init(file);
    solve();
    return 0;
}