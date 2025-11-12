#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int MOD = 998244353;
int c[N];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    //for(int i = 1;i <= n;i++){
    //    cin>>c[i];
   // }
    bool w = true;
    for(int i = 0;i < s.size();i++){
        if(s[i] != '1'){
            w = false;
        }
    }
    //if(w == true){
        int ans = 1;
        for(int i = 1;i <= n;i++){
            ans %= MOD;
            ans = ans * i % MOD;
            ans %= MOD;
        }
        cout<<ans;
    //}
    return 0;
}
