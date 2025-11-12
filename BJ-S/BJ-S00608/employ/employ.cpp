#include <bits/stdc++.h>
using namespace std;
bool s[505];
int a[505], b[505];
bool c[505];
int n, m;
long long dfs(int now, int p){
    if (now>n){
        if (p>=m) return 1;
        return 0;
    }
    long long ans=0;
    for (int i=1; i<=n; ++i){
        if (c[i]) continue;
        c[i]=1;
        if (s[i] && a[i]<b[now])
            ans=(ans+dfs(now+1, p+1))%998244353;
        else
            ans=(ans+dfs(now+1, p))%998244353;
        c[i]=0;
    }return ans;
}
int main(){
    bool tA=1;
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >>n >>m;
    for (int i=1; i<=n; ++i){
        char c;
        cin >> c;
        s[i]=c-'0';
        a[i]=a[i-1]+(!s[i]);
        if (s[i]==0) tA=0;
    }
    if (tA){
        long long ans=1;
        for (int i=2; i<=n; ++i)
            ans=(ans*i)%998244353;
        cout <<ans;
        return 0;
    }
    for (int i=1; i<=n; ++i){
        cin >>b[i];
    }
    cout <<dfs(1, 0);
    return 0;
}
