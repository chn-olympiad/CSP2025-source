#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
struct node{
    struct A{
        ll val;
        int id;
        friend bool operator < (A p, A q){
            return p.val > q.val;
        }
    }v[5];
}a[N];
int T, n, tot, c[5], t[N];

int main(){

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].v[1].val >> a[i].v[2].val >> a[i].v[3].val;
            a[i].v[1].id = 1, a[i].v[2].id = 2, a[i].v[3].id = 3;
            sort(a[i].v + 1, a[i].v + 4);
        }
        c[1] = c[2] = c[3] = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            c[a[i].v[1].id]++;
            ans += a[i].v[1].val;
        }
        ll tmp = max(c[1], max(c[2], c[3]));
        if(tmp <= (n / 2)){
            cout << ans << '\n';
            continue;
        }
        int ind;
        if(c[1] == tmp) ind = 1;
        else if(c[2] == tmp) ind = 2;
        else ind = 3;
        tot = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].v[1].id != ind) continue;
            t[++tot] = a[i].v[1].val - a[i].v[2].val;
        }
        sort(t + 1, t + tot + 1);
        for(int i = 1; i <= tmp - n / 2; i++)
            ans -= t[i];
        cout << ans << '\n';
    }

    return 0;
}
