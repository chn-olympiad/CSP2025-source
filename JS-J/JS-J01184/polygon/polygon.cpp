#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans = 0,maxg = 0,answer[5005];
bool choose[5005] = {};
long long A(long long an,long long b){
    long long anse = 1;
    for (long long i = 0;i < b;i++,an--){
        anse *= an;
        anse %= 998244353;
    }
    return anse % 998244353;
}
long long c(long long an,long long b){
    if (answer[b - an]){
        return answer[b - an];
    }
    answer[an] = A(an,b) / A(an,an) % 998244353;
    return answer[an];
}
void dfs(long long x,long long gotten){
    if (x == n){
        if (gotten < 3){
            return;
        }
        long long sum = 0,maxn = 0;
        for (long long i = 0;i < n;i++){
            if (choose[i]){
                sum += a[i];
                if (a[i] > maxn){
                    maxn = a[i];
                }
            }
        }
        if (sum > 2 * maxn){
            ans++;
            ans %= 998244353;
        }
        return;
    }
    choose[x] = 1;
    dfs(x + 1,gotten + 1);
    choose[x] = 0;
    dfs(x + 1,gotten);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (long long i = 0;i < n;i++){
        cin >> a[i];
        if (a[i] > maxg){
            maxg = a[i];
        }
    }
    if (maxg > 1){
        dfs(0,0);
        cout << ans % 998244353;
        return 0;
    }
    ans = 1;
    for (long long i = 3;i < n;i++){
        ans += c(i,n);
        ans %= 998244353;
    }
    cout << ans % 998244353;
    return 0;
}
