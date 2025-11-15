#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353, n, m, p[19];
string s;
int ans=0;
bool person[19];
void rec(int chosen, int num_of_reject){
    if(chosen==n){
        if(n-num_of_reject>=m){
            ans=(ans+1)%mod;
        }
        return;
    }
    for(int i=1; i<=n; i++){
        if(!person[i]){
            person[i]=true;
            if(s[chosen]=='0'||p[i]<=num_of_reject){
                rec(chosen+1, num_of_reject+1);
            }else{
                rec(chosen+1, num_of_reject);
            }
            person[i]=false;
        }
    }
    return;
}
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    rec(0, 0);
    cout << ans;
}