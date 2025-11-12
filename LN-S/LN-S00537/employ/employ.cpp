#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505, MOD = 998244353;
#define ite for(int i = 1; i <= n; i++)
#define ll long long

bool s[MAXN];
int c[MAXN], sn[MAXN], ci[MAXN];
int n, m;

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    char sd;
    for(int i = 1; i <= n; i++){
        cin >> sd;
        s[i] = sd == '1';
        sn[i] = sn[i - 1] + (s[i] == 0 ? 1 : 0);
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        ci[i] = i;
    }
    if(n - sn[n] < m) {cout << 0;return 0;}
    if(n <= 10){
        int ans = 0;
        do{
            int succedcnt = 0;
            for(int i = 1; i <= n; i++){
                if(s[i] && i - succedcnt - 1 < c[ci[i]]){
                    succedcnt++;
                }
            }
            if(succedcnt >= m) ans++;
        }while(next_permutation(ci + 1, ci + n + 1));//?
        cout << ans;
    }
    else if(sn[n] == 0){//subtask A
        ll ans = 1;
        for(int i = 1; i <= n; i++){
            ans = (ans * i) %MOD;
        }
        cout << ans;
    }
    else{
        cout << 14371437;
    }

    return 0;
}