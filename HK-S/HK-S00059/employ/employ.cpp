#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int32_t main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int c[500];
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    int cnt=0, c0=0;
    for(int i=0; i<n; i++){
        cnt += s[i]-'0';
        c0 += (c[i] == 0);
    }
    if(cnt < m || n-c0 < m){
        cout << "0\n";
        return 0;
    }

    if(n<=18){
        string s1 = "";
        int ans = 0;
        for(int i=0; i<n; i++){
            s1 += (char)('a' + i);
        }
        do{
            int fail = 0, sum=0;
            for(int i=0; i<n; i++){
                if(s[i] == '0' || fail >= c[s1[i]-'a']){
                    fail++;
                }else{
                    sum++;
                }
            }
            // cout << s1 << ' ' << fail << ' ' << sum << '\n';
            if(sum >= m) ans++;
        }while(next_permutation(s1.begin(), s1.end()));
        cout << ans % MOD;
    }/*else if(m == 1){
        sort(c, c+n);
        int ones = 0, l = 0;
        bool ok = 1;
        vector<int>ls;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ones++;
                if(c[i-ones] > ones) ok = 0;
                ls.push_back(l);
                l=0;
            }else{
                l++;
            }
        }
    }*/

    return 0;
}