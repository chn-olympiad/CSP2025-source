#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int a, b, c;
} nd[100010];

void solve(){
    priority_queue<int, vector<int>, greater<int> > pqa, pqb, pqc;
    int ans = 0;
    int a = 0, b = 0, c = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> nd[i].a >> nd[i].b >> nd[i].c;
        if (nd[i].a >= nd[i].b && nd[i].a >= nd[i].c){
            a++;
            ans += nd[i].a;
            pqa.push(min(nd[i].a - nd[i].b, nd[i].a - nd[i].c));
        }
        else if (nd[i].b >= nd[i].a && nd[i].b >= nd[i].c){
            b++;
            ans += nd[i].b;
            pqb.push(min(nd[i].b - nd[i].a, nd[i].b - nd[i].c));
        }
        else if (nd[i].c >= nd[i].a && nd[i].c >= nd[i].b){
            c++;
            ans += nd[i].c;
            pqc.push(min(nd[i].c - nd[i].a, nd[i].c - nd[i].b));
        }
    }
    if (a > n / 2){
        for (int i = 1; i <= a - n / 2; i++){
            ans -= pqa.top();
            pqa.pop();
        }
    }
    if (b > n / 2){
        for (int i = 1; i <= b - n / 2; i++){
            ans -= pqb.top();
            pqb.pop();
        }
    }
    if (c > n / 2){
        for (int i = 1; i <= c - n / 2; i++){
            ans -= pqc.top();
            pqc.pop();
        }
    }
    cout << ans << "\n";
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
