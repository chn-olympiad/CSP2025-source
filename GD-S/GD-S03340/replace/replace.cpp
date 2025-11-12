#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; i++)
int n, q;
pair<string, string> calc(string a, string b, int &from, int &to){
    int mn = 0, mx = a.size() - 1;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != b[i]){
            mn = i;
            break;
        }
    }
    for(int i = a.size() - 1 ; i >= 0 ; i--){
        if(a[i] != b[i]){
            mx = i;
            break;
        }
    }
    from = mn;
    to = mx;
    return make_pair(a.substr(mn, mx - mn + 1), b.substr(mn, mx - mn + 1));
}
unordered_map<string, vector<string>> pre; 
unordered_map<string, vector<pair<int, string>>> ask;
const int N = 5000000 + 10;
int son[N][27];
int endd[N];
int fail[N];
int cnt;
int f(char ch){
    if(ch >= 'a' && ch <= 'z')
        return ch - 'a';
    else 
        return 26;
}
void insert(string &s){
    int now = 0;
    for(char ch : s){
        int id = f(ch);
        if(!son[now][id]) 
            son[now][id] = ++cnt;
        now = son[now][id];
    }
    endd[now]++;
}
void build(){
    queue<int> q;
    for(int i = 0 ; i <= 26 ; i++)
        if(son[0][i])
            q.push(son[0][i]);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        rep(id, 0, 26){
            if(son[now][id]){
                fail[son[now][id]] = son[fail[now]][id];
                q.push(son[now][id]);
            }
            else 
                son[now][id] = son[fail[now]][id];
        }
    }
}
int query(string &s){
    int res = 0;
    vector<pair<int, int>> modi;
    int now = 0;
    for(auto ch : s){
        int id = f(ch);
        now = son[now][id];
        int tmp = now;
        while(tmp && endd[tmp] != -1){
            res += endd[tmp];
            modi.emplace_back(tmp, endd[tmp]);
            endd[tmp] = -1;
            tmp = fail[tmp];
        }
    }
    for(auto p : modi){
        endd[p.first] = p.second;
    }
    return res;
}
void clear(){
    rep(i, 0, cnt){
        rep(j, 0, 26) son[i][j] = 0;
        endd[i] = fail[i] = 0;
    }
    cnt = 0;
}
// #define DEBUG
int ans[N];
signed main(){
    #ifndef DEBUG
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    #endif 
    ios::sync_with_stdio(false);
    cin >> n >> q;
    rep(i, 1, n){
        string s, t;
        cin >> s >> t;
        if(s == t) continue;
        int from, to;
        pair<string, string> tmp = calc(s, t, from, to);
        string res;
        if(from)
            res += s.substr(0, from);
        int len = s.size() - to - 1;
        res += '$';
        if(len > 0){
            res += s.substr(to + 1, s.size() - to - 1);
        }
        pre[tmp.first + '$' + tmp.second].emplace_back(res);
    }
    // cerr << "input finished\n";
    rep(i, 1, q){
        string s, t;
        cin >> s >> t;
        int from, to;
        pair<string, string> tmp = calc(s, t, from, to);
        string res;
        if(from)
            res += s.substr(0, from);
        int len = s.size() - to - 1;
        res += '$';
        if(len > 0){
            res += s.substr(to + 1, s.size() - to - 1);
        }
        ask[tmp.first + '$' + tmp.second].emplace_back(i, res);
    }
    // cerr << "input finished\n";
    for(auto p : pre){
        // cerr << "onup\n";
        vector<string> ss = p.second;
        vector<pair<int, string>> asks = ask[p.first];
        for(auto &s : ss){
            insert(s);
        }
        // cerr << "insert done\n";
        build();
        // cerr << "build down\n";
        for(auto &vv : asks){
            int id = vv.first;
            ans[id] = query(vv.second);
        }
        // cerr << "query down\n";
        clear();
        // cerr << "ondown\n";
        // cerr << cnttt << '\n';
    }
    rep(i, 1, q)
        cout << ans[i] << '\n';
    return 0;
}