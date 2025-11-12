#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5+5;
int T, n;
struct Node{
    ll a, b, c;
    Node (ll _a = 0, ll _b = 0, ll _c = 0):
        a(_a), b(_b), c(_c) {}
} p[N];
void _main(){
    vector<int> a, b, c, abc, ab, bc, ac;
    cin >> n;
    int m = n / 2;
    for (int i=1;i<=n;i++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
        if(p[i].a > p[i].b && p[i].a > p[i].c) a.push_back(i);
        else if(p[i].b > p[i].a && p[i].b > p[i].c) b.push_back(i);
        else if(p[i].c > p[i].a && p[i].c >p[i].b) c.push_back(i);
        else if(p[i].a == p[i].b && p[i].b == p[i].c) abc.push_back(i);
        else if(p[i].a == p[i].b) ab.push_back(i);
        else if(p[i].b == p[i].c) bc.push_back(i);
        else ac.push_back(i);
    }
    for (int x : ab){
        if(a.size() < b.size()) a.push_back(x);
        else b.push_back(x);
    }
    for (int x : bc){
        if(b.size() < c.size()) b.push_back(x);
        else c.push_back(x);
    }
    for (int x : ac){
        if(a.size() < c.size()) a.push_back(x);
        else c.push_back(x);
    }

    int toA = m - a.size();
    int toB = m - b.size();
    int toC = m - c.size();

    if (a.size() > m) {
        sort(a.begin(), a.end(), [](int x, int y){
            return min(p[x].a - p[x].b, p[x].a - p[x].c) < min(p[y].a - p[y].b, p[y].a - p[y].c);
        });
        int cnt = 0, l = a.size() - m;
        for (auto it = a.begin(); it != a.end();){
            int u = *it;
            ll db = p[u].a - p[u].b, dc = p[u].a - p[u].c;
            if (db == dc){
                if (toB < toC) b.push_back(u), toB--;
                else c.push_back(u), toC--;
            }
            else if(db < dc) b.push_back(u), toB--;
            else c.push_back(u), toC--;
            it = a.erase(it);
            if (++cnt == l) break;
        }
    }else if (b.size() > m) {
        sort(b.begin(), b.end(), [](int x, int y){
            return min(p[x].b - p[x].a, p[x].b - p[x].c) < min(p[y].b - p[y].a, p[y].b - p[y].c);
        });
        int cnt = 0, l = b.size() - m;
        for (auto it = b.begin(); it != b.end();){
            int u = *it;
            ll da = p[u].b - p[u].a, dc = p[u].b - p[u].c;
            if (da == dc){
                if (toA < toC) a.push_back(u), toA--;
                else c.push_back(u), toC--;
            }
            else if(da < dc) a.push_back(u), toA--;
            else c.push_back(u), toC--;
            it = b.erase(it);
            if (++cnt == l) break;
        }
    }else if(c.size() > m){
        sort(c.begin(), c.end(), [](int x, int y){
            return min(p[x].c - p[x].a, p[x].c - p[x].b) < min(p[y].c - p[y].a, p[y].c - p[y].b);
        });
        int cnt = 0, l = c.size() - m;
        for (auto it = c.begin(); it != c.end();){
            int u = *it;
            ll da = p[u].c - p[u].a, db = p[u].c - p[u].b;
            if (da == db){
                if (toA < toB) a.push_back(u), toA--;
                else b.push_back(u), toB--;
            }
            else if(da < db) a.push_back(u), toA--;
            else b.push_back(u), toB--;
            it = c.erase(it);
            if (++cnt == l) break;
        }
    }

    ll ans = 0;

    for (int x : a) ans += p[x].a;
    for (int x : b) ans += p[x].b;
    for (int x : c) ans += p[x].c;
    for (int x : abc) ans += p[x].a;

    cout << ans << endl;
    return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while(T--) _main();
    return 0;
}