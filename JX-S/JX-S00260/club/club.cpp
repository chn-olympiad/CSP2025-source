#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct Node{
    long long num, s, d;
}t[N];
long long n, T;
long long res;
long long c[5];
long long a[4][N];
bool cmp(Node x,Node y) {
    return x.s < y.s;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        res = 0;
        c[1] = c[2] = c[3] = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[1][i] >> a[2][i] >> a[3][i];
            if(a[1][i] >= a[2][i] && a[1][i] >= a[3][i]) {
                res += a[1][i];
                c[1]++;
                if(a[2][i] >= a[3][i]) {
                    t[i].num = i;
                    t[i].s = a[1][i] - a[2][i];
                    t[i].d = 1;
                }
                else {
                    t[i].num = i;
                    t[i].s = a[1][i] - a[3][i];
                    t[i].d = 1;
                }
            }
            else if(a[2][i] >= a[3][i]) {
                res += a[2][i];
                c[2]++;
                if(a[1][i] >= a[3][i]) {
                    t[i].num = i;
                    t[i].s = a[2][i] - a[1][i];
                    t[i].d = 2;
                }
                else {
                    t[i].num = i;
                    t[i].s = a[2][i] - a[3][i];
                    t[i].d = 2;
                }
            }
            else {
                res += a[3][i];
                c[3]++;
                if(a[1][i] >= a[2][i]) {
                    t[i].num = i;
                    t[i].s = a[3][i] - a[1][i];
                    t[i].d = 3;
                }
                else {
                    t[i].num = i;
                    t[i].s = a[3][i] - a[2][i];
                    t[i].d = 3;
                }
            }
        }
        sort(t + 1,t + n + 1,cmp);
        for(int i = 1;i <= n;i++) {
            if(c[1] > n / 2) {
                if(t[i].d != 1)continue;
                c[1]--;
                res -= t[i].s;
            }
            else if(c[2] > n / 2) {
                if(t[i].d != 2)continue;
                c[2]--;
                res -= t[i].s;
            }
            else if(c[3] > n / 2) {
                if(t[i].d != 3)continue;
                c[3]--;
                res -= t[i].s;
            }
            else break;
        }
        cout << res << '\n';
    }
    return 0;
}
