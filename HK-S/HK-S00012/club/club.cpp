#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define x first
#define y second
const int N = 100005;
int t, n, f[N];
struct intt{
    int x, y, z;
}a[N];
bool t3(){
    bool flag = 1; for (int i = 1; i <= n; i++) flag = flag & ((a[i].y==0)&&(a[i].z==0));
    return flag;}
bool t2(){
    bool flag = 1; for (int i = 1; i <= n; i++) flag = flag & (a[i].z==0);
    return flag;}
bool cmp3(intt a, intt b) {return a.x > b.x;}
bool cmp2(intt a, intt b) {
    if (a.x != b.x) return a.x < b.x;
    else if (a.y != b.y)return a.y < b.y;
    else return a.z < b.z;
}
void solve(){
    cin >> n; vector<pii> vi;
    vi.clear(); int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
    if (t3()) {
        sort(a + 1, a + 1 + n, cmp3);
        for (int i = 1; i <= n/2; i++) ans += a[i].x;
        return;
    }
    else if (t2()) {
        for (int i = 1; i <= n; i++) vi.push_back({a[i].x - a[i].y, i});
        sort(vi.begin(), vi.end(), greater<pii>());
        for (int i = 0; i < n/2;i++) ans += a[vi[i].y].x;
        for (int i = n / 2; i < n;i++) ans += a[vi[i].y].y;
        cout << ans << "\n";
        return;
    }
    vector<pair<int, pii>> v;
    v.clear();ans = 0;
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) {
        v.push_back({a[i].x-a[i].y-a[i].z,{1,i}});
        v.push_back({a[i].y-a[i].z-a[i].x,{2,i}});
        v.push_back({a[i].z-a[i].y-a[i].x,{3,i}});
    }
    sort(v.begin(), v.end(), greater<pair<int,pii>>());
    int cnt[4] = {0,0,0,0};
    for (int i = 0; i < v.size(); i++) {
        int g = v[i].y.x;
        if (cnt[g] < n/2 && f[v[i].y.y]==0) cnt[g]++;
        else continue;
        f[v[i].y.y] = 1;
        if (g==1) ans += a[v[i].y.y].x;
        else if (g==2) ans += a[v[i].y.y].y;
        else ans += a[v[i].y.y].z;
        if (cnt[1]+cnt[2]+cnt[3]==n) break;
    }
     cout << ans << "\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--) solve();
    fclose(stdin); fclose(stdout);
}
