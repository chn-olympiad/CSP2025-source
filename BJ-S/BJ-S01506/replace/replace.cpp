#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid (l + r >> 1)
using namespace std;

const int N = 2e5 + 5;
int n, q, c[N], dis[N], l[N], r[N], ans;
string s1[N], s2[N], t1, t2;
inline void solve1(){
    while(q--){
        cin >> t1 >> t2;
        if (t1.size() != t2.size()){
            printf("0\n");
            continue;
        }
        int m = t1.size();
        if (t1 == t2){
            for (int i = 1; i <= n; i++){
                if (s1[i] != s2[i]) continue;
                t2 = t1;
                int x = t2.find(s1[i]);
                int pp = s1[i].size();
                while(x < t2.size()){
                    t2 = t2.substr(x + pp, t2.size());
                    x = t2.find(s1[i]);
                    ans++;
                }
            }
            printf("%d\n", ans);
            continue;
        }
        ans = 0;
        for (int i = 1; i <= n; i++){
            int x = t1.find(s1[i]);
            int y = t2.find(s2[i]);
            int pp = s1[i].size();
            if (x == y && x < t1.size()){
                if (t1.substr(0, x) == t2.substr(0, x) && t1.substr(x + pp, m) == t2.substr(x + pp, m)){
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}
int main(){
   //freopen("data.in", "r", stdin);
   //freopen("T3.out", "w", stdout);
   freopen("replace.in", "r", stdin);
   freopen("replace.out", "w", stdout);
   scanf("%d%d", &n, &q);
   for (int i = 1; i <= n; ++i){
       cin >> s1[i] >> s2[i];
   }
    solve1();
   return 0;
}
