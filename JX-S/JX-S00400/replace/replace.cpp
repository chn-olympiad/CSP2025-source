#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, l, r) for(int i = (r); i >= (l); i--)
#define FRE(NAME) freopen(NAME".in", "r", stdin), freopen(NAME".out", "w", stdout);
#define int long long
#define endl '\n'
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
const int mod = 1000000007;

int qpow(int q, int p){
    int res = 1;
    while(p != 0){
        if(p % 2) res *= q, res %= mod;
        q = q * q, q %= mod, p /= 2;
    }
    return res;
}

vector<int> haash(string s){
    vector<int> res(s.size());
    int cnt = 0;
    rep(i, 0, s.size() - 1){
        int now = s[i] - 'a';
        cnt *= 31;
        cnt += now;
        cnt %= mod;
        res[i] = cnt;
    }
    return res;
}

int gethash(string s){
    int cnt = 0;
    rep(i, 0, s.size() - 1){
        int now = s[i] - 'a';
        cnt *= 31;
        cnt += now;
        cnt %= mod;
    }
    return cnt;
}

vector<int> is_son(string s, string t){ // t is s's son
    vector<int> res;
    vector<int> hhash = haash(s);
    int hasht = gethash(t);
    rep(i, t.size() - 1, s.size() - 1){
        int minus = 0;
        if(i - t.size() == -1){
            minus = 0;
        }else{
            minus = hhash[i - t.size()] * qpow(31, t.size());
            minus %= mod;
        }
        if((hhash[i] + mod - minus) % mod == hasht){
            res.push_back(i);
        }
    }
    return res;
}

i32 main(){
    FRE("replace");
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<string> s1(n), s2(n);
    vector<string> t1(q), t2(q);
    rep(i, 0, n - 1) cin >> s1[i] >> s2[i];
    rep(i, 0, q - 1){
        cin >> t1[i] >> t2[i];
        if(t1[i].size() != t2[i].size()){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        int L = -1, R = 0;
        rep(j, 0, t1[i].size() - 1){
            if(t1[i][j] != t2[i][j]){
                R = j;
                if(L == -1) L = j;
            }
        }
        rep(j, 0, n - 1){
            vector<int> son1 = is_son(t1[i], s1[j]);
            vector<int> son2 = is_son(t2[i], s2[j]);
            vector<int> son3;
            int I = 0, J = 0;
            while(I < son1.size() && J < son2.size()){
                if(son1[I] == son2[J]) son3.push_back(son1[I]), I++, J++;
                else if(son1[I] < son2[J]) I++;
                else J++;
            }
            for(auto u : son3){
                // cout << u << endl;
                int r = u, l = u - s1[j].size() + 1;
                if(l <= L && R <= r){
                    ans++;
                    // cout << j << endl;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
g++ replace.cpp -o replace -Wall -Wextra -O2 -g3 -DQwQ
./replace
*/