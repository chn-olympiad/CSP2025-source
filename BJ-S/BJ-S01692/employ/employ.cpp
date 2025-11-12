#include <bits/stdc++.h>
using namespace std;
const int maxn = 550, mod = 998244353;
int c[maxn];
int main(){
//    freopen("employ.in", "r", stdin);
//    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    bool flag = true;
    int cnt = 0;
    for(int i = 0;i < s.size();i++){if(s[i] != '1') flag = false; else cnt++;}
    for(int i = 1;i <= n;i++) cin >> c[i];
    int cnt2 = n, cnt3 = 0;
    for(int i = 1;i <= n;i++) if(c[i] == 0){cnt2--; cnt3++;}
    if(flag){
        if(cnt2 >= m){
            long long sum = 1;
            int t = cnt2;
            while(t > 0){
                sum *= t;
                t--;
                sum %= mod;
            }
            sum *= cnt3;
            sum %= mod;
            cout << sum;
        }
    }
    else if(m == 1){
        if(cnt >= 1 && cnt2 >= m){
            long long sum = 1;
            int t = n;
            while(t > 0){
                sum *= t;
                t--;
                sum %= mod;
            }
            cout << sum;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
