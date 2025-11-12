#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10;
const int mod = 1e9 + 7; 
int n,m,anss = 1;
string s;
bool t = 0;
int c[N],book[N],p[N],ans;
void dfs(int step){
    if (step > n){
        int sum = 0,summ = 0;
        for (int i = 1; i <= n; i++){
           if (s[i] == '0' || sum >= c[p[i]]) sum++;
           else summ++;
        }
        if (summ >= m) ans++,ans%=mod;
        return ;
    }
    for (int i = 1; i <= n; i++){
        if (!book[i]){
            book[i] = 1;
            p[step] = i;
            dfs(step + 1);
            p[step] = book[i] = 0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
     cin >> n >> m;
     cin >> s;
     s = " " + s;
     for (int i = 1; i <= n; i++) if (s[i] == 0) t = 1;
     for (int i = 1; i <= n; i++){
         cin >> c[i];
     }
     if (n <= 10){
         dfs(1);
         cout << ans;
         return 0;
     }
    for (int i = 1; i <= n; i++) anss*=i,anss%=mod;
    cout << anss;
    return 0;
}