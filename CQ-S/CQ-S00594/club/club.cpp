#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int MAXN = 1e5 + 100;

int n;

struct NODE {
    int x, y, z;
    bool operator <(const NODE &a) const{
        return a.x - max(a.y, a.z) < x - max(y, z);
    } 
} a;

struct NODE2 {
    int x, y, z;
    bool operator <(const NODE2 &a) const{
        return a.y - max(a.x, a.z) < y - max(x, z);
    } 
} b;

struct NODE3 {
    int x, y, z;
    bool operator <(const NODE3 &a) const{
        return a.z - max(a.y, a.x) < z - max(y, x);
    } 
} c;
priority_queue<NODE> pq1; 
priority_queue<NODE2> pq2; 
priority_queue<NODE3> pq3; 
void solve() {
    int n; cin >> n;
    while(pq1.size()) pq1.pop();
    while(pq2.size()) pq2.pop();
    while(pq3.size()) pq3.pop();
    for(int i = 1; i <= n; i ++) {
        cin >> a.x >> a.y >> a.z;
        b.x = c.x = a.x;
        b.y = c.y = a.y;
        b.z = c.z = a.z;
        int mx = max({a.x, a.y, a.z});
        if(a.x == mx) {
            pq1.push(a);
            if(pq1.size() > n / 2) {
                NODE tmp = pq1.top(); pq1.pop();
                if(tmp.y > tmp.z) pq2.push((NODE2){tmp.x, tmp.y, tmp.z});
                else pq3.push((NODE3){tmp.x, tmp.y, tmp.z});
            } 
        } else if(a.y == mx) {
            pq2.push(b);
            if(pq2.size() > n / 2) {
                NODE2 tmp = pq2.top(); pq2.pop();
                if(tmp.x > tmp.z) pq1.push((NODE){tmp.x, tmp.y, tmp.z});
                else pq3.push((NODE3){tmp.x, tmp.y, tmp.z});
            } 
        }else {
            pq3.push(c);
            if(pq3.size() > n / 2) {
                NODE3 tmp = pq3.top(); pq3.pop();
                if(tmp.y > tmp.x) pq2.push((NODE2){tmp.x, tmp.y, tmp.z});
                else pq1.push((NODE){tmp.x, tmp.y, tmp.z});
            } 
        }
    }
    int ans = 0;
    while(pq1.size()) {
        ans += pq1.top().x, pq1.pop();
    }
    while(pq2.size()) {
        ans += pq2.top().y, pq2.pop();
    }
    while(pq3.size()) {
        ans += pq3.top().z, pq3.pop();
    }
    cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(0);
	 freopen("club.in", "r", stdin);
	 freopen("club.out", "w", stdout);
    int T; cin >> T;
    while(T --) solve();
	return 0;
}
