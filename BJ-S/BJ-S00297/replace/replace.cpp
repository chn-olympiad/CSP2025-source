#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define gtnm(x,y) ((x - 'a') * 26 + (y - 'a'))

const int N = 2e5 + 5,L = 5e6 + 5;

string s[N][2],t[N][2],ss[N],ts[N];
int sl[N],sr[N],tl[N],tr[N];
unordered_map<string,int> mp,gtre;
struct Node{
    int id,op;
};
vector<Node> cls[N << 1];

int n,q;

unordered_map<int,int> ch[L];
vector<int> inc[L];
int cnt;

void clear(){
    for(int i = 1;i <= cnt;i++) inc[i].clear(),ch[i].clear();
    cnt = 1;
}

void insert(int id,string s0,string s1){
    int now = 1;
    for(int i = 0;i < s0.size();i++){
        int c = gtnm(s0[i],s1[i]);
        if(ch[now][c] == 0) ch[now][c] = ++cnt;
        now = ch[now][c];
    }
    inc[now].push_back(id);
}

unordered_map<int,int> sum[N];

void qry(int id,string s0,string s1){
    int now = 1;
    for(int x : inc[now]) sum[id][x]++;
    for(int i = 0;i < s0.size();i++){
        int c = gtnm(s0[i],s1[i]);
        if(ch[now][c] == 0) return;
        now = ch[now][c];
        for(int x : inc[now]) sum[id][x]++;
    }
}

int fa[N],able[N];

int ans[N];

int tot;

string reverse(string s){
    string t;
    for(int i = s.size() - 1;i >= 0;i--){
        t += s[i];
    }
    return t;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][0] >> s[i][1];
        string tmp = s[i][0] + s[i][1];
        if(gtre[tmp] == 0) gtre[tmp] = i;
        else{
            // cerr << i << ' ' << gtre[tmp] << endl;
            able[gtre[tmp]]++;
            continue;
        }
        able[gtre[tmp]] = 1;
        int a = -1,b = 0;
        for(int j = 0;j < s[i][0].size();j++){
            if(a == -1 && s[i][0][j] != s[i][1][j]) a = j;
            if(s[i][0][j] != s[i][1][j]) b = j;
        }
        if(a == -1){
            continue;
        }
        ss[i] = s[i][0].substr(a,b - a + 1) + s[i][1].substr(a,b - a + 1);
        if(mp[ss[i]] == 0) mp[ss[i]] = ++tot;
        cls[mp[ss[i]]].push_back({i,0});

        sl[i] = a;
        sr[i] = b;
    }
    gtre.clear();
    for(int i = 1;i <= q;i++){
        cin >> t[i][0] >> t[i][1];
        fa[i] = i;
        if(t[i][0].size() != t[i][1].size()) continue;
        string tmp = t[i][0] + t[i][1];
        if(gtre[tmp] == 0) gtre[tmp] = i;
        else{
            fa[i] = gtre[tmp];
            continue;
        }
        int a = -1,b = 0;
        for(int j = 0;j < t[i][0].size();j++){
            if(a == -1 && t[i][0][j] != t[i][1][j]) a = j;
            if(t[i][0][j] != t[i][1][j]) b = j;
        }
        ts[i] = t[i][0].substr(a,b - a + 1) + t[i][1].substr(a,b - a + 1);
        if(mp[ts[i]] == 0) mp[ts[i]] = ++tot;
        cls[mp[ts[i]]].push_back({i,1});

        tl[i] = a;
        tr[i] = b;
    }

    for(auto x : mp){
        int id = x.second;
        clear();
        for(int i = 0;i < cls[id].size();i++){
            if(cls[id][i].op == 0){
                int nm = cls[id][i].id;
                insert(nm,s[nm][0].substr(sr[nm] + 1),s[nm][1].substr(sr[nm] + 1));
            }else{
                int nm = cls[id][i].id;
                // cerr << nm << ' ' << tr[nm] + 1 << endl;
                qry(nm,t[nm][0].substr(tr[nm] + 1),t[nm][1].substr(tr[nm] + 1));
            }
        }

        clear();
        // cerr << sum[1][1] << endl;
        for(int i = 0;i < cls[id].size();i++){
            if(cls[id][i].op == 0){
                int nm = cls[id][i].id;
                // cerr << nm << endl;
                // cerr << s[nm][0].substr(0,sl[nm]) << ' ' << s[nm][1].substr(0,sl[nm]) << endl;
                insert(nm,reverse(s[nm][0].substr(0,sl[nm])),reverse(s[nm][1].substr(0,sl[nm])));
            }else{
                int nm = cls[id][i].id;
                // cerr << t[nm][0].substr(0,tl[nm]) << ' ' << t[nm][1].substr(0,tl[nm]) << endl;
                qry(nm,reverse(t[nm][0].substr(0,tl[nm])),reverse(t[nm][1].substr(0,tl[nm])));
                // cerr << sum[1][1] << endl;
                for(auto y : sum[nm]){
                    // cerr << y.first << ' ' << y.second << endl;
                    if(y.second == 2){
                        ans[nm] += able[y.first];
                    }
                }
                sum[nm].clear();
            }
        }
    }

    for(int i = 1;i <= q;i++){
        cout << ans[fa[i]] << '\n';
    }
}