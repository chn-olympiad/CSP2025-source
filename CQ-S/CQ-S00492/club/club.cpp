#include <bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int

#define endl "\n"
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

#define pii pair<int, int>
#define pll pair<ll, ll>

// #define x first
// #define y second

using namespace std;

const int inf = 2e9;
const ll INF = 2e18;
const int mod = 1e9 + 7;
const db eps = 1e-6;
const int maxn = 1e5 + 5;
const int N = 1e7 + 7;

void solve() {
    struct Node {
        int v, id;
    } ;

    int n; cin >> n;
    vector<vector<Node>> a(n + 1, vector<Node>(3));
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0].v >> a[i][1].v >> a[i][2].v;
        a[i][0].id = 1, a[i][1].id = 2, a[i][2].id = 3;
        sort(all(a[i]), [&](auto &x, auto &y) {
            return x.v > y.v;
        }) ;
    }

//	cerr << "ok1" << endl;

    vector<int> c1, c2, c3;
    for (int i = 1; i <= n; i++) {
        if (a[i][0].id == 1) c1.push_back(i);
        if (a[i][0].id == 2) c2.push_back(i);
        if (a[i][0].id == 3) c3.push_back(i);
    }
    
//    cerr << c1.size() << ' ' << c2.size() << ' ' << c3.size() << endl;

    ll sum = 0;
    auto calc = [&](vector<int> &b) -> void {
        vector<Node> mid;
        for (int i = 0; i < (int)b.size(); i++) {
        	Node x;
        	x.v = a[b[i]][0].v - a[b[i]][1].v;
            x.id = b[i];
            mid.push_back(x);
        }
        b.clear();
        sort(all(mid), [&](auto &x, auto &y) {
            return x.v > y.v;
        }) ;
        for (int i = 0; i < (n / 2); i++) b.push_back(mid[i].id);
        for (int i = n / 2; i < (int)mid.size(); i++) sum += a[mid[i].id][1].v;
    } ;
    
    if ((int)c1.size() > n / 2) calc(c1);
    if ((int)c2.size() > n / 2) calc(c2);
    if ((int)c3.size() > n / 2) calc(c3);
    
//    cerr << "ok3" << endl;

    for (auto id : c1) sum += a[id][0].v;
    for (auto id : c2) sum += a[id][0].v;
    for (auto id : c3) sum += a[id][0].v;
    
//    cerr << "ok4" << endl;

    cout << sum << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0

*/

