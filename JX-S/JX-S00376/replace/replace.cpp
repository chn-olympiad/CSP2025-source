#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int pw = 131;
int n,m,sum1[N],sum2[N],sum3[N],sum4[N],h[N];
string s1[N],s2[N],t1[N],t2[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> m;
    h[0] = 1;
    for (int i = 1; i <= N-10; i++) h[i] = (h[i-1]*pw)%mod;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i],s1[i] = " " + s1[i],s2[i] = " " + s2[i];
    for (int i = 1; i <= m; i++) cin >> t1[i] >> t2[i],t1[i] = " " + t1[i],t2[i] = " " + t2[i];
    for (int i = 1; i <= m; i++){
        int ans = 0;
        for (int j = 1; j < t1[i].size(); j++) sum3[j] = (sum3[j-1]*pw)%mod + (int)(t1[i][j] - 'a' + 1);
        for (int j = 1; j < t2[i].size(); j++) sum4[j] = (sum4[j-1]*pw)%mod + (int)(t2[i][j] - 'a' + 1);
        if (t1[i].size() != t2[i].size()){
            cout << 0 << '\n';
            continue;
        }
        int y = t1[i].size() - 1;
        for (int j = 1; j <= n; j++){
            for (int k = 1; k < s1[j].size(); k++){
                sum1[k] = (sum1[k-1]*pw)%mod + (int)(s1[j][k] - 'a' + 1);
            }
            for (int k = 1; k < s2[j].size(); k++){
                sum2[k] = (sum2[k-1]*pw)%mod + (int)(s2[j][k] - 'a' + 1);
            }
            int x = s1[j].size() - 1;
            for (int k = s1[j].size()-1; k < t1[i].size(); k++){
                if ((sum3[k] - (sum3[k - x]*h[x]%mod) + mod)%mod == sum1[x]){
                    int f1 = (((sum3[k - x]*h[x]%mod + mod)%mod + sum2[x])%mod*h[y - k])%mod;
                    int f2 = (sum3[y] - sum3[k]*h[y - k]%mod + mod)%mod;
                    if ((f1 + f2)%mod == sum4[y]%mod) ans++;
                  //  if (ans == 1) cout << i << " " << j << " " << k << " " <<" "<< sum3[k] <<  '\n'; 
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}