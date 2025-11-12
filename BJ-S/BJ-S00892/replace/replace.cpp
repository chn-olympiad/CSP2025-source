#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define int long long
using namespace std;
int cntb, cnta;
string s1[200010], s2[200010], t1[200010], t2[200010];
struct R
{
    int bp1, bp2, id;
}ss[200010], ts[200010];
bool cmp(R x, R y) {
    if(x.bp2 - x.bp1 != y.bp2 - y.bp1) return x.bp2 - x.bp1 < y.bp2 - y.bp1;
    else return x.bp1 < y.bp1;
}
int c[5000010];
int lowbit(int x) {
    return x & (-x);
}
void add(int p, int num) {
    for(int i = p; i <= 5000005; i += lowbit(i)) c[i] += num;
}
int fd(int p) {
    int res = 0;
    for(int i = p; i; i -= lowbit(i)) res += c[i];
    return res;
}
int anss[200010];
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        for(int j = 0; j < s1[i].size(); j++) if(s1[i][j] == 'b') cntb++;
        for(int j = 0; j < s2[i].size(); j++) if(s2[i][j] == 'b') cntb++;
    }
    for(int i = 1; i <= q; i++) {
        cin >> t1[i] >> t2[i];
        for(int j = 0; j < t1[i].size(); j++) if(t1[i][j] == 'b') cntb++;
        for(int j = 0; j < t2[i].size(); j++) if(t2[i][j] == 'b') cntb++;
    }
    if(cntb == 2 * (n + q)) {
        for(int i = 1; i <= n; i++) {
            ss[i].id = i;
            for(int j = 0; j < s1[i].size(); j++) if(s1[i][j] == 'b') ss[i].bp1 = j;
            for(int j = 0; j < s2[i].size(); j++) if(s2[i][j] == 'b') ss[i].bp2 = j;
        }
        for(int i = 1; i <= q; i++) {
            ts[i].id = i;
            for(int j = 0; j < t1[i].size(); j++) if(t1[i][j] == 'b') ts[i].bp1 = j;
            for(int j = 0; j < t2[i].size(); j++) if(t2[i][j] == 'b') ts[i].bp2 = j;
        }
        //cout << "foofoo\n";
        sort(ss + 1, ss + n + 1, cmp);
        sort(ts + 1, ts + q + 1, cmp);
        int lstcur = 0, cur = 1, curdis = -1e9;
        for(int i = 1; i <= q; i++) {
            if(curdis != ts[i].bp2 - ts[i].bp1) {
                for(int j = lstcur + 1; j < cur; j++) add(s1[ss[j].id].size() - ss[j].bp1, -1);
                lstcur = cur - 1;
                curdis = ts[i].bp2 - ts[i].bp1;
            }
            while(cur <= n && ss[cur].bp2 - ss[cur].bp1 < ts[i].bp2 - ts[i].bp1) lstcur++, cur++;
            while(cur <= n && ss[cur].bp2 - ss[cur].bp1 == ts[i].bp2 - ts[i].bp1 && ss[cur].bp1 <= ts[i].bp1) add(s1[ss[cur].id].size() - ss[cur].bp1, 1), cur++;
            anss[ts[i].id] = fd(t1[ts[i].id].size() - ts[i].bp1);
        }
        for(int i = 1; i <= q; i++) cout << anss[i] << '\n';
        return 0;
    }
    string tt, tt2, tt3;
    for(int i = 1; i <= q; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(s1[j].size() > t1[i].size()) continue;
            //cout << t1[i].size() << ' ' << s1[j].size() << '\n';
            for(int k = 0; k < t1[i].size() - s1[j].size() + 1; k++) {
                tt = "";
                for(int l = 0; l < s1[j].size(); l++) tt += t1[i][k + l];
                //cout << tt.size() << '\n';
                if(tt == s1[j]) {
                    tt2 = t1[i];
                    for(int l = 0; l < s1[j].size(); l++) tt2[k + l] = s2[j][l];
                    //cout << tt2 << '\n';
                    if(tt2 == t2[i]) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}