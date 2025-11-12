#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node{
    int a,b,c;
}s[maxn];
int cmp(Node a, Node b) {
    return a.a - a.b > b.a - b.b;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
   int t; cin >> t;
   while(t--){
        int n;
        long long cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i].a >> s[i].b >> s[i].c;
        }
         if (n == 2) {
            cout << max(max(max((s[0].a + s[1].b), (s[0].a + s[1].c)),max((s[0].b + s[1].a), (s[0].b + s[1].c))), max((s[0].c + s[1].a), (s[0].c + s[1].b))) << '\n';
            continue;
        }
        sort(s, s + n, cmp);
        for (int i = 0; i < n / 2; i++) {
            cnt += s[i].a;
        }
        for (int i = n / 2; i < n; i++) {
            cnt += s[i].b;
        }
        cout << cnt << '\n';
   }
}
