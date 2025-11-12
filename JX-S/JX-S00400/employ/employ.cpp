#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, l, r) for(int i = (r); i >= (l); i--)
#define FRE(NAME) freopen(NAME".in", "r", stdin), freopen(NAME".out", "w", stdout);
#define int long long
#define endl '\n'
using namespace std;
using i32 = int32_t;
using i64 = int64_t;

int n, m;
string s;
int ans = 0;
vector<int> cc;

bool check(vector<int> now){
    // rep(i, 1, n) cout << now[i] << " ";
    // cout << endl;
    int fq = 0, Yes = 0;
    rep(i, 1, n){
        if(fq >= now[i] || s[i] == '0') fq++;
        else Yes++;
    }
    if(Yes >= m) return 1;
    return 0;
}

void dfs(vector<int> use, int cnt, vector<int> now){
    // cout << cnt << endl;
    if(cnt == n){
        ans += check(now);
        return;
    }
    rep(i, 1, n){
        if(use[i] == 0){
            use[i] = 1;
            now.push_back(cc[i]);
            dfs(use, cnt + 1, now);
            now.pop_back();
            use[i] = 0;
        }
    }
}

i32 main(){
    FRE("employ");
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    vector<int> c(n + 1);
    rep(i, 1, n) cin >> c[i];
    cc = c;
    vector<int> use(n + 1);
    vector<int> now(1);
    dfs(use, 0, now);
    cout << ans << endl;
    return 0;
}

/*
g++ employ.cpp -o employ -Wall -Wextra -O2 -g3 -DQwQ
./employ
*/