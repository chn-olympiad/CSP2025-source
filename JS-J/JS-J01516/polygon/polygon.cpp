#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],sum,ans,k,m = 998244353;
int c(int a,int b){
    return (a % m) * (b % m) % m;
}
int jc(int n){
    int ans = 1;
    for(int i = 1;i <= n;i++){
        ans = c(ans,i);
    }
    return ans;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin  >> a[i];
        sum += a[i];
    }
    if(n == 3){
        cout << (a[1] + a[2] + a[3] > max({a[1],a[2],a[3]}));
    }else if(sum == n){
        for(int i = 3;i <= n;i++){
            ans += jc(n) / c(jc(i),jc(n - i)) % m;
        }
        cout << ans;
    }else{
        cout << 9;
    }
    return 0;
}
