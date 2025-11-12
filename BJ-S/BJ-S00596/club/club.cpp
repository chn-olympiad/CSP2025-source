#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct Node{
    int a, b, c;
}a[100005];
inline bool cmp(Node x, Node y){
    bool fx = (x.a == max(x.a, max(x.b, x.c)));
    bool fy = (y.a == max(y.a, max(y.b, y.c)));
    if(fx != fy) return fx > fy;
    return x.a > y.a;
}
int n;
priority_queue<int, vector<int>, greater<int> > q;
inline void Solve(){
    while(!q.empty()) q.pop();
    n = read();
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; i++){
        a[i].a = read(), a[i].b = read(), a[i].c = read();
        int mx = max(a[i].a, max(a[i].b, a[i].c));
        if(mx == a[i].a) cnt1++;
        if(mx == a[i].b) cnt2++;
        if(mx == a[i].c) cnt3++;
    }
    int Lim = n / 2;
    if(cnt1 <= Lim && cnt2 <= Lim && cnt3 <= Lim){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += max(a[i].a, max(a[i].b, a[i].c));
        }
        cout << ans << '\n';
        return;
    }
    // cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    if(cnt2 > Lim){
        for(int i = 1; i <= n; i++) swap(a[i].a, a[i].b);
        swap(cnt1, cnt2);
    }
    if(cnt3 > Lim){
        for(int i = 1; i <= n; i++) swap(a[i].a, a[i].c);
        swap(cnt1, cnt3);
    }
    sort(a + 1, a + 1 + n, cmp);
    // for(int i = 1; i <= n; i++){
    //     cout << a[i].a << " " << a[i].b << " " << a[i].c << endl;
    // }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i <= Lim){
            ans += a[i].a;
            q.push(a[i].a - max(a[i].b, a[i].c));
        }else{
            ans += max(a[i].b, a[i].c);
        }
    }
    // cout << ans << endl << endl;
    for(int i = Lim + 1; i <= n; i++){
        if(a[i].a == max(a[i].a, max(a[i].b, a[i].c))){
            int u = q.top(), newu = a[i].a - max(a[i].b, a[i].c);
            if(u < newu){
                q.pop(); q.push(newu);
                ans += newu - u;
            }
        }
    }
    cout << ans << '\n';
    return;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while(T--) Solve();
    return 0;
}