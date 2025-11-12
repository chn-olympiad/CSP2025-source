#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n, m, a[MAXN], id[MAXN]; string s;

signed main(){
    freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> s; s = " " + s;
    for(int i = 1; i <= n; ++i) cin >> a[i], id[i] = i;
    int ans = 0;
    do{
        int res = 0;
        for(int i = 1; i <= n; ++i){
            if(s[i] == '0' || res >= a[id[i]]) res++;
        }
        ans += (n - res >= m);
    }while(next_permutation(id + 1, id + n + 1));
    cout << ans;

    return 0;
}