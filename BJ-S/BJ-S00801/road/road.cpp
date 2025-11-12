# include <iostream>
# include <cstdio>
# include <queue>
//# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

const int csb = 10003;

struct City {
    int blm;
    //int num;
    int vis;
    unordered_map<int, int> next = {};
    //int cct;
    int cost;
} mp[10015];

int n, m, k, u, v, w, ans;
bool f=1;
//vector <City *> fs;
//int mp[10015][10015];
//int ulk_m[15];

int main() {
    freopen("road3.in", "r", stdin);
    freopen("road3.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        mp[u].next[v] = w+1;
        mp[v].next[u] = w+1;
    }
    for (int i=1; i<=k; i++) {
        cin >> mp[i+csb].blm;
        mp[i+csb].blm++;
        for (int j=1; j<=n; j++) {
            cin >> mp[i+csb].next[j];
            mp[i+csb].next[j]++;
            //mp[j].next[i+csb] = mp[i+csb].next[j];
        }
    }

    mp[1].vis = 1;
    for (int i=2; i<=n; i++) {
        int miM = 2147483640, cct=-1;
        for (auto j: mp[i].next) {
            if (miM > j.second-1) {
                miM = j.second-1;
                //ct = j.first;
            }
            //cout << i << ' ' << j.first << ' ' << j.second-1 << endl;
        }
        if (miM != 2147483640) {
            ans += miM;
            //mp[i].cct = cct;
            mp[i].cost = miM;
        }
    }
    //for (int i=2; i<=n; i++) {
    //    for (int j=1; j<=k; j++) {
    //        int temp = mp[csb+i].next[mp[i].cct];
    //        if (!mp[csb+i].vis) {
    //            temp += mp[csb+i].blm;
    //        }
    //        if (temp < mp[i].cost) {
    //            ans -= mp[i].cost;
    //            mp[i].cost = temp;
    //            ans += temp;
    //            if (!mp[csb+i].vis) {
    //                mp[csb+i].vis = 1;
    //            }
    //        }
    //    }
    //}
    cout << ans;
    return 0;
}
