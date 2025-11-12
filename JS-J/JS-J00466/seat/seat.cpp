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
    bool no_in = 0, no_out = 0;
};


o4 void init(IOFiles &file){
    cstr in = file.in, out = file.out;
    if (in != ""){
        if (! file.no_in) freopen(in, "r", stdin);
        if (! file.no_out) freopen(out, "w", stdout);
    }
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int a[101][101];

IOFiles file{"seat.in", "seat.out"};
def solve(){
    int n, m; cin >> n >> m;
    int k; cin >> k;
    int biggers = 0;
    for(int i = 0;i < n*m-1;i ++){
        int v; cin >> v;
        if (v > k) biggers ++;
    }
    int order = biggers + 1;
    int c = (order + n- 1) / n;
    int r = order % n;
    if (c % 2 == 0){
        r = n - r;
    }
    if (r == 0) r = n - r;
    cout << c << ' ' << r;
}


int main(){
    init(file);
    solve();
}