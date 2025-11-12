#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 10;

int n;

struct node {
    int a1, a2 ,a3;
} t[N];

bool operator<(const node&a, const node&b) {
    int mx1 = max(a.a1, max(a.a2, a.a3)), mx2 = max(max(b.a1, b.a2), b.a3);
    int md1 = a.a1 + a.a2 + a.a3 - mx1 - min(min(a.a1, a.a2), a.a3);
    int md2 = b.a1 + b.a2 + b.a3 - mx2 - min(b.a1, min(b.a2, b.a3));
    return (mx1 - md1) > (mx2 - md2);
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while(T --) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> t[i].a1 >> t[i].a2 >> t[i].a3;
        }
        int lim = n / 2;
        int sm = 0;
        int cnt[4] = {};
        priority_queue<node> q[4];  
        for(int i = 1; i <= n; i ++) {
            int mx = max(max(t[i].a1, t[i].a2), t[i].a3);
            int ii;
            if(mx == t[i].a1) ii = 1;
            if(mx == t[i].a2) ii = 2;
            if(mx == t[i].a3) ii = 3;
            q[ii].push(t[i]);
        }
        if(max({q[1].size(), q[2].size(), q[3].size()}) <= lim);
        else {
            int ip;
            if(q[1].size() > lim) ip = 1;
            if(q[2].size() > lim) ip = 2;
            if(q[3].size() > lim) ip = 3;
            while(q[ip].size() > lim) {
                node u = q[ip].top(); q[ip].pop();
                int mx = max(max(u.a1, u.a2), u.a3);
                int md = u.a1 + u.a2 + u.a3 - mx - min(min(u.a1, u.a2), u.a3);
                int ii;
                if(md == u.a1 and ip != 1) ii = 1;
                if(md == u.a2 and ip != 2) ii = 2;
                if(md == u.a3 and ip != 3) ii = 3;
                q[ii].push(u);
            }
        }
        while(!q[1].empty()) sm += q[1].top().a1, q[1].pop();
        while(!q[2].empty()) sm += q[2].top().a2, q[2].pop();
        while(!q[3].empty()) sm += q[3].top().a3, q[3].pop();
        
        cout << sm << '\n';
    }
    return 0;
}