#include<bits/stdc++.h>
using namespace std;

struct fix {int l, r;};
int const inf = 1 << 20 + 7;
int const N = 5e5 + 7;
int a[N], f[1005][1005];
int t[N];
int n, k;

void dbug(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << f[i][j] << " ";
        } cout << "\n";
    }
}

bool cmp(fix &q, fix &e){
    if(q.l != e.l) return q.l < e.l;
    return q.r < e.r;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) f[i][i] = a[i];

    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            if(l == r) continue;
            f[l][r] = f[l][r - 1] ^ a[r];
        }
    }

    int ans = 0;
    vector<fix> pos;
    for(int l = 1; l <= n; l++){
        for(int r = l; r <= n; r++){
            if(f[l][r] == k) pos.push_back({l, r});
        }
    }

    // sort(pos.begin(), pos.end(), cmp);

    int R = 0;
    for(int i = 0; i < pos.size(); i++){
        int l = pos[i].l, r = pos[i].r;
        // cout << l << " " << r << "\n";
        if(l > R){
            R = r;
            ans ++;
            continue;
        }
    }

    // dbug();

    cout << ans << "\n";

    return 0;
}

// bl
// Kasty's code