#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ch[5] = {0, 0, 0};
struct Node{
    int a, b, c, mx, t, mx2, t2, cha;
    bool operator< (const Node o) const{
        return cha > o.cha;
    }
}d[N];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >>T;
    while(T--){
        int n; cin >> n;
        int mid = n / 2;
        long long ans = 0;
        memset(ch, 0, sizeof(ch));
        memset(d, 0, sizeof(d));
        for(int i = 1; i <= n; i++){
            cin >> d[i].a >> d[i].b >> d[i].c;
            d[i].mx = max({d[i].a, d[i].b, d[i].c});
            if(d[i].mx == d[i].a){
                d[i].t = 1;
                if(d[i].b > d[i].c) d[i].mx2 = d[i].b, d[i].t2 = 2;
                else d[i].mx2 = d[i].c, d[i].t2 = 3;
            }
            if(d[i].mx == d[i].b){
                d[i].t = 2;
                if(d[i].a > d[i].c) d[i].mx2 = d[i].a, d[i].t2 = 1;
                else d[i].mx2 = d[i].c, d[i].t2 = 3;
            }
            if(d[i].mx == d[i].c){
                d[i].t = 3;
                if(d[i].a > d[i].b) d[i].mx2 = d[i].a, d[i].t2 = 1;
                else d[i].mx2 = d[i].b, d[i].t2 = 2;
            }
            d[i].cha = d[i].mx - d[i].mx2;
        }
        sort(d + 1, d + n + 1);
        for(int i = 1; i <= n; i++){
            int mx = d[i].mx;
            int mx2 = d[i].mx2;
            int t = d[i].t;
            int t2 = d[i].t2;
            if(ch[t] == mid) ch[t2]++, ans += mx2;
            else ch[t]++, ans += mx;
        }
        cout << ans <<endl;
    }
}
