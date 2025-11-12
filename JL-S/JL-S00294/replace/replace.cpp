#include <bits/stdc++.h>
using namespace std;
struct node{
    int l, r;
}r1[200001], r2[200001];
int n, q;
string a[200001], b[200001], c[200001], d[200001];
void solve(string x, string y){
    int all = 0;
    for (int i = 1; i <= n; i++){
        int cnt = 0, t1 = x.find(a[i]), t2 = y.find(b[i]);
        while (t1 < x.size() && t2 < y.size()){
            if (t1 == t2){
                string c1 = x, c2 = y;
                for (int j = t1; j <= t1 + a[i].size() - 1; j++){
                    c1[j] = b[i][j - t1];
                }
                bool flag = true;
                if (c1.size() != c2.size()){
                    flag = false;
                } else{
                    for (int i = 0; i < c1.size(); i++){
                        if (c1[i] != c2[i]){
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag){
                    cnt++;
                }
            }
            x[t1] = 'S';
            y[t2] = 'S';
            t1 = x.find(a[i]);
            t2 = x.find(b[i]);
        }
        all += cnt;
    }
    cout << all << endl;
}
void solve2(string x, string y){
    int k1 = x.find("b"), k2 = y.find("b");
    int cnt1L = 0, cnt1R = 0, cnt2L = 0, cnt2R = 0;
    int t = k1 - 1;
    while (t >= 0 && x[t] == 'a'){
        cnt1L++;
        t--;
    }
    t = k1 + 1;
    while (t < x.size() && x[t] == 'a'){
        cnt1R++;
        t++;
    }
    t = k2 - 1;
    while (t >= 0 && y[t] == 'a'){
        cnt2L++;
        t--;
    }
    t = k2 + 1;
    while (t < y.size() && y[t] == 'a'){
        cnt2R++;
        t--;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (r1[i].l <= cnt1L && r1[i].r <= cnt1R && r2[i].l <= cnt2L && r2[i].r <= cnt2R){
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= q; i++){
        cin >> c[i] >> d[i];
    }
    if (n <= 100 && q <= 100){
        for (int i = 1; i <= q; i++){
            solve(c[i], d[i]);
        }
        return 0;
    } else if (q == 1){
        solve(c[1], d[1]);
        return 0;
    }
    for (int i = 1; i <= n; i++){
        int x = a[i].find("b");
        int y = b[i].find("b");
        r1[i].l = x;
        r1[i].r = a[i].size() - x - 1;
        r2[i].l = y;
        r2[i].r = b[i].size() - y - 1;
    }
    for (int i = 1; i <= q; i++){
        solve(c[i], d[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
