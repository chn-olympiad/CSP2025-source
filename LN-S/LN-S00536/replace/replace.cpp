#include <bits/stdc++.h>

using namespace std;

using ci = const int;
using ll = long long;

ci N = 2e5 + 5;

template <typename T>
inline void cmax(T& x,const T y) {if(y > x) x = y;}

template <typename T>
inline void cmin(T& x,const T y) {if(y < x) x = y;}

namespace qwq {
    int n,q;
    string s1[N],s2[N],t1,t2,t;
    int qwq_main() {
        freopen("replace.in","r",stdin);
        freopen("replace.out","w",stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr),cout.tie(nullptr);
        cin >> n >> q;
        for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
        for(int qi = 1,cnt;qi <= q;qi++) {
            cin >> t1 >> t2;
            cnt = 0;
            for(int i = 1,pos,len,lst;i <= n;i++) {
                len = s1[i].size();
                if(len > t1.size()) continue;
                t = t1;
                pos = t.find(s1[i]);
                if(pos == t.npos) continue;
                for(int j = 0;j < len;j++) t[pos + j] = s2[i][j];
                while(t != t2) {
                    t = t1;
                    lst = pos + 1;
                    pos = t.substr(pos + 1).find(s1[i]);
                    if(pos == t.npos) break;
                    pos += lst;
                    for(int j = 0;j < len;j++) t[pos + j] = s2[i][j];
                }
                if(t == t2) cnt++;
            }
            cout << cnt;
            if(qi != q) cout << "\n";
            else cout << endl;
        }
        return 0;
    }
}

int main() {
    return qwq::qwq_main();
}