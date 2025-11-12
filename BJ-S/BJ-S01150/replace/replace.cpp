#include <bits/stdc++.h>
using namespace std;

string s1[200001], s2[200001], t1[200001], t2[200001];
long long sum1[3000001], sum2[3000001], p[3000001], sum[200001], sum3[200001], mod = 1e9 + 7;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s1[i] >> s2[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> t1[i] >> t2[i];
    }
    p[0] = 1;
    for(int i = 1; i <= 3000000; i++){
        p[i] = p[i - 1] * 131 % mod;
    }
    for(int i = 1; i <= n; i++){
        int len = s1[i].size();
        for(int j = 1; j <= len; j++){
            sum[i] = (sum[i] * 131 + s1[i][j - 1] - 'a' + 1) % mod;
        }
        for(int j = 1; j <= len; j++){
            sum3[i] = (sum3[i] * 131 + s2[i][j - 1] - 'a' + 1) % mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(t1[i].size() != t2[i].size()){
            cout << "0\n";
            continue;
        }
        ans = 0;
        int len = t1[i].size(), fir = 1e9, lst = 1;
        for(int j = 1; j <= len; j++){
            sum1[j] = (sum1[j - 1] * 131 + t1[i][j - 1] - 'a' + 1) % mod;
            if(t1[i][j - 1] != t2[i][j - 1]){
                lst = j;
                fir = min(fir, j);
            }
        }
        for(int j = 1; j <= len; j++){
            sum2[j] = (sum2[j - 1] * 131 + t2[i][j - 1] - 'a' + 1) % mod;
        }
        for(int j = 1; j <= len; j++){
            for(int k = 1; k <= n; k++){
                int len2 = s1[k].size();
                if(j + len2 - 1 > len){
                    continue;
                }
                if(((sum1[j + len2 - 1] - sum1[j - 1] * p[len2]) % mod + mod) % mod == sum[k]
                && ((sum2[j + len2 - 1] - sum2[j - 1] * p[len2]) % mod + mod) % mod == sum3[k]
                && j <= fir && j + len2 - 1 >= lst){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}