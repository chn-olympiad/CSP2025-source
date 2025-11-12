#include <iostream>
#include <cstdio>
#define MAXN 200005
using namespace std;
int n, q;
string s[MAXN][2];
int dif[MAXN], len[MAXN];
string st, ed;
bool re(int x, int y, int xx, int yy) {
    for(int i=xx; i<=yy; i++) {
        if(s[y][1][i-x]!=ed[i]) {
            return false;
        }
    }
    return true;
}
int find(string x, int ss, int len) {
    int qwq = x.length();
    for(int i=ss; i<len; i++) {
        if(i+qwq-1>=len) {
            return -1;
        }
        bool f = true;
        for(int j=0; j<qwq; j++) {
            if(st[i+j]!=x[j]) {
                f = false;
                break;
            }
        }
        if(f) {
            return i;
        }
    }
    return -1;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> s[i][0] >> s[i][1];
        len[i] = s[i][0].length();
        for(int j=0; j<len[i]; j++) {
            if(s[i][0][j]!=s[i][1][j]) {
                dif[i] ++;
            }
        }
    }
    while(q--) {
        cin >> st >> ed;
        int dst = -1, ded = 0, diffe = 0, cnt = 0;
        int qaq = st.length();
        for(int i=0; i<qaq; i++) {
            if(st[i]!=ed[i]) {
                if(dst==-1) {
                    dst = i;
                }
                ded = i;
                diffe ++;
            }
        }
        for(int i=1; i<=n; i++) {
            if(dif[i]!=diffe||len[i]<ded-dst+1) {
                continue;
            }
            int pos = find(s[i][0], 0, qaq);
            if(pos==-1) {
                continue;
            }
            while(1) {
                if(pos+len[i]-1<ded) {
                    continue;
                }
                if(pos>dst) {
                    break;
                }
                if(re(pos, i, dst, ded)) {
                    cnt ++;
                    break;
                }
                pos = find(s[i][0], pos+1, qaq);
                if(pos==-1) {
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
