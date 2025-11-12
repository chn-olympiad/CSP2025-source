//LMY bao you wo zheng jie bie gua!!!~~~
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define lop(i, x, y) for (int i = x; i >= y; i--)
using namespace std;
typedef unsigned long long ull;
const int NR = 2e5 + 5;
const int MAXN = 5e6 + 5;
const ull base = 13331;
ull pw[MAXN];
int n, Q;
string str[4][NR];
int len[4][NR];
struct Node{
    int l, r;
    ull dat;
}bt1[NR], bt2[NR];
vector<ull> hsh[4][NR];
ull get(int o, int i, int l, int r){
    return hsh[o][i][r] - pw[r - l + 1] * hsh[o][i][l - 1];
}
int maxlen;
map<pair<int, ull>, int> mp;
int tot;
vector<int> vec[NR];
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> Q;
    pw[0] = 1;
    rep(i, 1, 5000000) pw[i] = pw[i - 1] * base;
    rep(i, 1, n){
        rep(j, 0, 1){
            cin >> str[j][i];
            len[j][i] = str[j][i].size();
            str[j][i] = '#' + str[j][i];
            hsh[j][i].push_back(0);
            rep(k, 1, len[j][i]){
                ull cur = hsh[j][i][hsh[j][i].size() - 1] * base + (ull)str[j][i][k];
                hsh[j][i].push_back(cur);
            }
            maxlen = max(maxlen, len[j][i]);
        }
        bt1[i].l = -1, bt1[i].r = -1;
        rep(j, 1, len[0][i]){
            if (str[0][i][j] != str[1][i][j]){
                bt1[i].l = j;
                break;
            }
        }
        lop(j, len[0][i], 1){
            if (str[0][i][j] != str[1][i][j]){
                bt1[i].r = j;
                break;
            }
        }
        if (bt1[i].l == -1) continue;
        bt1[i].dat = get(0, i, bt1[i].l, bt1[i].r) * pw[bt1[i].r - bt1[i].l + 1] + get(1, i, bt1[i].l, bt1[i].r);
        pair<int, ull> lmy = make_pair(bt1[i].r - bt1[i].l + 1, bt1[i].dat);
        if (!mp.count(lmy)){
            tot++;
            mp[lmy] = tot;
        }
        vec[mp[lmy]].push_back(i);
    }
    rep(i, 1, Q){
        rep(j, 2, 3){
            cin >> str[j][i];
            len[j][i] = str[j][i].size();
            str[j][i] = '#' + str[j][i];
            hsh[j][i].push_back(0);
            rep(k, 1, len[j][i]){
                ull cur = hsh[j][i][hsh[j][i].size() - 1] * base + (ull)str[j][i][k];
                hsh[j][i].push_back(cur);
            }
            maxlen = max(maxlen, len[j][i]);
        }
        bt2[i].l = -1, bt2[i].r = -1;
        rep(j, 1, len[2][i]){
            if (str[2][i][j] != str[3][i][j]){
                bt2[i].l = j;
                break;
            }
        }
        lop(j, len[2][i], 1){
            if (str[2][i][j] != str[3][i][j]){
                bt2[i].r = j;
                break;
            }
        }
        bt2[i].dat = get(2, i, bt2[i].l, bt2[i].r) * pw[bt2[i].r - bt2[i].l + 1] + get(3, i, bt2[i].l, bt2[i].r);
    }
    rep(i, 1, Q){
        pair<int, ull> lyc = make_pair(bt2[i].r - bt2[i].l + 1, bt2[i].dat);
        int ans = 0;
        if (mp.count(lyc)){
            int id = mp[lyc];
            for (auto kv : vec[id]){
                bool flag = false;
                rep(j, 1, len[2][i] - len[0][kv] + 1){
                    ull a = get(2, i, j, j + len[0][kv] - 1), b = get(3, i, j, j + len[0][kv] - 1);
                    ull c = get(0, kv, 1, len[0][kv]), d = get(1, kv, 1, len[0][kv]);
                    if (a == c && b == d){
                        flag = true;
                        break;
                    }
                }
                if (flag == true) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
