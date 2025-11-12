#include<bits/stdc++.h>
using namespace std;
char __a;
const int N = 1e7 + 5, M = 26, K = 2e5 + 5;
int n, q, id;
string a[K][2], que[K][2];
vector<pair<int, int> >v[N];
char __b;
int main(){
    // cerr << (&__b - &__a) / 1048576.0 << " MB\n";
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> a[i][0] >> a[i][1];
        int len = a[i][0].length();
        int fst = n, ed = 0;
        for(int j = 0;j < len;j++){
            if(a[i][0][j] == a[i][1][j])continue;
            fst = min(fst, j), ed = max(ed, j);
        }
        if(fst > ed)continue;
        // cerr << fst << " " << ed << " len=" << len << "\n";
        v[ed - fst].push_back({i, fst});
    }
    for(int i = 1;i <= q;i++){
        cin >> que[i][0] >> que[i][1];
        if(que[i][0].length() != que[i][1].length()){
            cout << "0\n";
            continue;
        }
        int len = que[i][0].length();
        int fst = n, ed = 0;
        for(int j = 0;j < len;j++){
            if(que[i][0][j] == que[i][1][j])continue;
            fst = min(fst, j), ed = max(ed, j);
        }
        if(fst > ed){
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for(auto pos : v[ed - fst]){
            int ni = pos.first, bg = pos.second, tail = bg + ed - fst;
            int len0 = bg - a[ni][0].length();
            for(int j = 0;j < a[ni][0].length();j++){
                int nj = j + fst - bg;
                if(nj < 0 || nj >= len){
                    goto no1;
                }
                if(a[ni][0][j] != que[i][0][nj] || a[ni][1][j] != que[i][1][nj]){
                    goto no1;
                }
                
            }
            ans++;
            no1:;
        }
        cout << ans << "\n";
    }
    return 0;
}