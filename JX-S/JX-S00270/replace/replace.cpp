#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
string a[MAXN], b[MAXN];
int n, m;
long long h1[MAXN];
long long p1[MAXN];
int visl[MAXN];
int visr[MAXN];
int awz[MAXN];
int bwz[MAXN];
int main() {
    //4:30
    //zui hou 90 min
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> m;
    if((n <= 100 && m <= 100)) {
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            for(int j = 0; j < a[i].size(); j++) {
                if(a[i][j] == 'b') {
                    awz[i] = j;
                }
                if(b[i][j] == 'b') {
                    bwz[i] = j;
                }
            }
        }
        while(m--) {
            string sa, sb;
            cin >> sa >> sb;
            int result = 0;
            for(int i = 1; i <= n; i++){
                if(a[i].size() > sa.size()) {
                    continue;
                }
                if(a[i].size() == sa.size()) {
                    if(a[i] == sa and b[i] == sb) {
                        result++;
                    }
                }
                bool ok = 0;
                for(int l = 0; l < sa.size(); l++) {
                    for(int r = 0; r < a[i].size(); r++) {
                        //cout << a[i][r] << ' ' << sa[l + r] << endl;
                        if(l + r >= a[i].size()) {
                            ok = 1;
                            break;
                        }
                        if(a[i][r] != sa[l + r] ){
                            ok = 1;
                            break;
                        }
                        if(b[i][r] != sb[l + r]) {
                            ok = 1;
                            break;
                        }
                    }
                    for(int ll = 0; ll < l; ll++) {
                        if(sa[ll] != sb[ll]) {
                            ok = 1;
                            break;
                        }
                    }
                    //cout << l + a[i].size() << "-" << sa.size() << endl;
                    for(int rr = l + a[i].size(); rr < sa.size(); rr++) {
                        if(sa[rr] != sb[rr]) {
                            ok = 1;
                            break;
                        }
                    }


                    if(!ok) {
                        //cout << "l:" << l << ' ' << i << endl;
                        result++;
                    }
                }
            }
            cout << result << endl;
        }
    } else {
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            for(int j = 0; j < a[i].size(); j++) {
                if(a[i][j] == 'b') {
                    awz[i] = j;
                }
                if(b[i][j] == 'b') {
                    bwz[i] = j;
                }
            }
        }
        while(m--) {
            string sa, sb;
            cin >> sa >> sb;
            int wzsa, wzsb;
            for(int i = 0; i < sa.size(); i++) {
                if(sa[i] == 'b') {
                    wzsa = i;
                }
                if(sb[i] == 'b') {
                    wzsb = i;
                }
            }
            //cout << wzsa << ' ' << wzsb << endl;
            int result = 0;
            for(int i = 1; i <= n; i++) {
                if(a[i].size() > sa.size()) {
                    continue;
                }
                //cout << bwz[i] << ' ' << awz[i] << endl;
                if(wzsa < bwz[i] or wzsb < bwz[i]) {
                    continue;
                }
                if(sa.size() - wzsa < a[i].size() - awz[i]) {
                    continue;
                }

                if(sb.size() - wzsb < b[i].size() - bwz[i]) {
                    continue;
                }
                result++;
            }
            cout << result << endl;
        }
    }
    //te shu xing zhi
    return 0;
}
