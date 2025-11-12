#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n;

long long a1[maxn], a2[maxn], a3[maxn];
int a[maxn], b[maxn], c[maxn];
int cnta = 0, cntb = 0, cntc = 0;
long long ans = 0;

void init(int n){
    ans = 0;
    for(int i = 1;i <= n;i++){
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
    cnta = cntb = cntc = 0;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        init(n);
        for(int i = 1;i <= n;i++){
            cin >> a1[i] >> a2[i] >> a3[i];
            if(a1[i] > a2[i] && a1[i] > a3[i]){
                cnta++;
                a[cnta] = i;
            }
            if(a2[i] > a1[i] && a2[i] > a3[i]){
                cntb++;
                b[cntb] = i;
            }
            if(a3[i] > a1[i] && a3[i] > a2[i]){
                cntc++;
                c[cntc] = i;
            }
        }
        if(cnta > n / 2){
            sort(a + 1, a + cnta + 1);
            int t = cnta - n / 2;
            for(int i = 1;i <= t;i++){
                cnta--;
                int id = a[i];
                a[i] = 0;
                if(a2[id] > a3[id]){
                    cntb++;
                    b[cntb] = id;
                }
                else {
                    cntc++;
                    c[cntc] = id;
                }
            }
        }
        else if(cntb > n / 2){
            sort(b + 1, b + cntb + 1);
            int t = cntb - n / 2;
            for(int i = 1;i <= t;i++){
                cntb--;
                int id = b[i];
                b[i] = 0;
                if(a1[id] > a3[id]){
                    cnta++;
                    a[cnta] = id;
                }
                else {
                    cntc++;
                    c[cntc] = id;
                }
            }
        }
        else if(cntc > n / 2){
            sort(c + 1, c + cntc + 1);
            int t = cntc - n / 2;
            for(int i = 1;i <= t;i++){
                cntc--;
                int id = c[i];
                c[i] = 0;
                if(a2[id] > a1[id]){
                    cntb++;
                    b[cntb] = id;
                }
                else {
                    cnta++;
                    a[cnta] = id;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            if(a[i] == 0)continue;
            int id = a[i];
            ans += a1[id];
        }
        for(int i = 1;i <= n;i++){
            if(b[i] == 0)continue;
            int id = b[i];
            ans += a2[id];
        }
        for(int i = 1;i <= n;i++){
            if(c[i] == 0)continue;
            int id = c[i];
            ans += a3[id];
        }
        cout << ans << endl;
    }
    return 0;
}
