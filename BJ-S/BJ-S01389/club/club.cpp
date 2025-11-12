#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll T, n, ans, a[100010][10], b[100010], c[100010], d[100010];
bool f1, f2, f3;
bool Cmp(ll y, ll z){
    return y > z;
}
void Dfs2a(ll x, ll br, ll cr, ll an){
    if(x == n + 1){
        ans = max(ans, an);
        return;
    }
    if(br < n / 2){
        Dfs2a(x + 1, br + 1, cr, an + a[x][2]);
    }
    if(cr < n / 2){
        Dfs2a(x + 1, br, cr + 1, an + a[x][3]);
    }
    return;
}
void Dfs2b(ll x, ll ar, ll cr, ll an){
    if(x == n + 1){
        ans = max(ans, an);
        return;
    }
    if(ar < n / 2){
        Dfs2b(x + 1, ar + 1, cr, an + a[x][1]);
    }
    if(cr < n / 2){
        Dfs2b(x + 1, ar, cr + 1, an + a[x][3]);
    }
    return;
}
void Dfs2c(ll x, ll ar, ll br, ll an){
    if(x == n + 1){
        ans = max(ans, an);
        return;
    }
    if(ar < n / 2){
        Dfs2c(x + 1, ar + 1, br, an + a[x][1]);
    }
    if(br < n / 2){
        Dfs2c(x + 1, ar, br + 1, an + a[x][2]);
    }
    return;
}
void Dfs3(ll x, ll ar, ll br, ll cr, ll an){
    if(x == n + 1){
        ans = max(ans, an);
        return;
    }
    if(ar < n / 2){
        Dfs3(x + 1, ar + 1, br, cr, an + a[x][1]);
    }
    if(br < n / 2){
        Dfs3(x + 1, ar, br + 1, cr, an + a[x][2]);
    }
    if(cr < n / 2){
        Dfs3(x + 1, ar, br, cr + 1, an + a[x][3]);
    }
    return;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--){
        ans = 0;
        f1 = false;
        f2 = false;
        f3 = false;
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            b[i] = a[i][1];
            c[i] = a[i][2];
            d[i] = a[i][3];
            if(a[i][1] != 0){
                f1 = true;
            }
            if(a[i][2] != 0){
                f2 = true;
            }
            if(a[i][3] != 0){
                f3 = true;
            }
        }
        if(!f2 && !f3){
            sort(b + 1, b + 1 + n, Cmp);
            for(ll i = 1; i <= n / 2; i++){
                ans += b[i];
            }
        }
        else if(!f1 && !f3){
            sort(c + 1, c + 1 + n, Cmp);
            for(ll i = 1; i <= n / 2; i++){
                ans += c[i];
            }
        }
        else if(!f1 && !f2){
            sort(d + 1, d + 1 + n, Cmp);
            for(ll i = 1; i <= n / 2; i++){
                ans += d[i];
            }
        }
        else if(!f1){
            Dfs2a(1, 0, 0, 0);
        }
        else if(!f2){
            Dfs2b(1, 0, 0, 0);
        }
        else if(!f3){
            Dfs2c(1, 0, 0, 0);
        }
        else{
            Dfs3(1, 0, 0, 0, 0);
        }
        cout << ans << endl;
    }
    return 0;
}
