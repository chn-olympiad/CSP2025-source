#include <bits/stdc++.h>
using namespace std;
const int MOD =  998244353;
int n, m, oi[501], ans = 0;
bool abled[501];
int t[501];
string s;
bool flagspa = true;
int main(){
    // freopen("employ.in", "r", stdin);
    // freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++){
        t[i + 1] = i + 1;
        cin >> oi[i + 1];
        abled[i + 1] = s[i] - '0';
        if (!abled[i + 1]) flagspa = false;
    }
    if (flagspa){
        cout << 0;
        return 0;
    }
    do{
        int day = 1, empee = 1, fcnt = 0, ecnt = 0;
        while (day <= n && empee <= n){
            while (fcnt >= oi[empee]) empee++, fcnt++;
            if (abled[day]) empee++, fcnt++;
            else empee++, ecnt++;
        }
        if (ecnt >= m) ans = (ans + 1) % MOD;
    }while (next_permutation(t + 1, t + n + 1));
    printf("%d", ans);
    return 0;
}
