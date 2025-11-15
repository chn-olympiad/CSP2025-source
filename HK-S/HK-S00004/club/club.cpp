#include <bits/stdc++.h>
using namespace std;
#define tendoualice
#ifdef tendoualice
ifstream input("club.in");
ofstream output("club.out");
#define cin input
#define cout output
#endif

#define ll long long

struct node{
    ll a, b, c;
};

bool cmp1(node a, node b){
    return a.a > b.a;
}

bool cmp2(node a, node b){
    return a.b > b.b;
}

bool cmp3(node a, node b){
    return a.c > b.c;
}

ll av[30], bv[30], cv[30];

ll dfs(int n, int ac, int bc, int cc){
    if(ac + bc + cc == n) return 0;
    ll ans = 0;
    if(ac + 1 <= n / 2) ans = max(ans, dfs(n, ac + 1, bc, cc) + av[ac + bc + cc]);
    if(bc + 1 <= n / 2) ans = max(ans, dfs(n, ac, bc + 1, cc) + bv[ac + bc + cc]);
    if(cc + 1 <= n / 2) ans = max(ans, dfs(n, ac, bc, cc + 1) + cv[ac + bc + cc]);
    return ans;
}

void solve2(int n){
    for(int i = 0; i < n; i++) cin >> av[i] >> bv[i] >> cv[i];
    cout << dfs(n, 0, 0, 0) << endl;
}

void solve(){
    int n;
    cin >> n;
    if(n <= 30){
        solve2(n);
        return;
    }
    vector<node> a(n + 1);
    bool spea = true, speb = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i].a >> a[i].b >> a[i].c;
        spea = spea and (a[i].b == 0 and a[i].c == 0);
        speb = speb and (a[i].c == 0);
    }
    if(spea){
        sort(a.begin(), a.end(), cmp1);
        ll sum = 0;
        for(int i = 1; i <= n / 2; i++) sum += a[i].a;
        cout << sum << endl;
        return;
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++) sum += max({a[i].a, a[i].b, a[i].c});
    cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// g++ -O2 -std=c++14 -static club.cpp -o club