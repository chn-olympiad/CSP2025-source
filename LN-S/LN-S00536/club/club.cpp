#include <bits/stdc++.h>

using namespace std;

using ci = const int;
using ll = long long;

ci N = 1e5 + 5;

template <typename T>
inline void cmax(T& x,const T y) {if(y > x) x = y;}

template <typename T>
inline void cmin(T& x,const T y) {if(y < x) x = y;}

namespace qwq {
    int n;
    struct aaa {
        ll a[5];
        ll s,minv,maxv;
    } p[N];
    struct node {
        ll val;
        int cnt[5];
    } w[N][5];
    void check(int x,int id) {
        ll nval;
        bool flg = 0;
        for(int i = 1;i <= 3;i++) {
            nval = w[x - 1][i].val + p[x].a[id];
            if(nval > w[x][id].val) {
                if(w[x - 1][i].cnt[id] + 1 > n / 2) continue;
                flg = 1;
                w[x][id].cnt[1] = w[x - 1][i].cnt[1];
                w[x][id].cnt[2] = w[x - 1][i].cnt[2];
                w[x][id].cnt[3] = w[x - 1][i].cnt[3];
                w[x][id].cnt[id]++;
                w[x][id].val = nval;
            }
        }
        if(!flg) {
            for(int i = 1;i <= 3;i++) {
                nval = w[x - 1][i].val + p[x].a[id];
                if(nval >= w[x][id].val) {
                    if(w[x - 1][i].cnt[id] + 1 > n / 2) continue;
                    flg = 1;
                    w[x][id].cnt[1] = w[x - 1][i].cnt[1];
                    w[x][id].cnt[2] = w[x - 1][i].cnt[2];
                    w[x][id].cnt[3] = w[x - 1][i].cnt[3];
                    w[x][id].cnt[id]++;
                    w[x][id].val = nval;
                    break;
                }
            }
        }
    }
    ll subtask2_ans;
    void dfs(int d,int c1,int c2,int c3,ll val) {
        if(d == n + 1) {
            cmax(subtask2_ans,val);
            return ;
        }
        if(c1 + 1 <= n / 2) dfs(d + 1,c1 + 1,c2,c3,val + p[d].a[1]);
        if(c2 + 1 <= n / 2) dfs(d + 1,c1,c2 + 1,c3,val + p[d].a[2]);
        if(c3 + 1 <= n / 2) dfs(d + 1,c1,c2,c3 + 1,val + p[d].a[3]);
    }
    void subtask() {
        if(n == 2) {
            ll ans = 0;
            for(int i = 1;i <= 3;i++) {
                for(int j = 1;j <= 3;j++) {
                    if(i == j) continue;
                    cmax(ans,p[1].a[i] + p[2].a[j]);
                }
            }
            cout << ans;
        } else if(n <= 10) {
            subtask2_ans = 0;
            dfs(1,0,0,0,0);
            cout << subtask2_ans;
        }
    }
    void subtask3() {
        sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[1] > y.a[1]);});
        ll ans = 0;
        for(int i = 1;i <= n / 2;i++) ans += p[i].a[1];
        cout << ans;
    }
    int qwq_main() {
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr),cout.tie(nullptr);
        int t;
        cin >> t;
        ll ans1,ans2,ans3,ans4,ans5,ans6,ans7;
        for(int ti = 1;ti <= t;ti++) {
            cin >> n;
            bool subtask3_flg = true;
            for(int i = 1;i <= n;i++) {
                cin >> p[i].a[1] >> p[i].a[2] >> p[i].a[3];
                p[i].s = p[i].a[1] + p[i].a[2] + p[i].a[3];
                p[i].minv = min({p[i].a[1],p[i].a[2],p[i].a[3]});
                p[i].maxv = max({p[i].a[1],p[i].a[2],p[i].a[3]});
                if(p[i].a[2] != 0) subtask3_flg = false;
                if(p[i].a[3] != 0) subtask3_flg = false;
            }
            if(subtask3_flg) {
                subtask3();
                if(ti != n) cout << "\n";
                else cout << endl;
                continue;
            }
            if(n <= 10) {
                subtask();
                if(ti != n) cout << "\n";
                else cout << endl;
                continue;
            }
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[1] < y.a[1]);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans1 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[1] > y.a[1]);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans1,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[2] < y.a[2]);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans2 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[2] > y.a[2]);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans2,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[3] < y.a[3]);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans3 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.a[3] > y.a[3]);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans3,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.minv < y.minv);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans4 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.minv > y.minv);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans4,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.maxv < y.maxv);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans5 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.maxv > y.maxv);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans5,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.s < y.s);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans6 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return (x.s > y.s);});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans6,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return ((x.maxv - x.minv) < (y.maxv - y.minv));});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            ans7 = max({w[n][1].val,w[n][2].val,w[n][3].val});
            memset(w,0,sizeof(w));
            sort(p + 1,p + n + 1,[](aaa& x,aaa& y) {return ((x.maxv - x.minv) > (y.maxv - y.minv));});
            for(int i = 1;i <= n;i++) check(i,1),check(i,2),check(i,3);
            cmax(ans7,max({w[n][1].val,w[n][2].val,w[n][3].val}));

            cout << max({ans1,ans2,ans3,ans4,ans5,ans6,ans7});
            if(ti != n) cout << "\n";
            else cout << endl;
        }
        return 0;
    }
}

int main() {
    return qwq::qwq_main();
}