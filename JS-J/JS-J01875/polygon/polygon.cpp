#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int a[5010],n,ans;
bool solve(vector<int>v){
    int maxa = 0,sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum+=v[i];
        maxa = max(maxa,v[i]);
    }if (sum > maxa*2)return true;
    return false;
}
int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }if (n <= 2){
        ans = 0;
    }else if (n == 3){
        sort(a+1,a+4,greater<int>());
        if (a[2]+a[3] > a[1] && a[1]-a[3] < a[2]){
            ans++;
        }
    }else{
        for (int i = 3; i <= n; i++){
            long long m = 1,x = 1;
            int d = n;
            for (int j = i; j >= 1; j--,d--){
                m = (m*d)%MOD;
                x = (x*j)%MOD;
            }
            ans+=m/x;
        }
    }cout << ans;
    return 0;
}
