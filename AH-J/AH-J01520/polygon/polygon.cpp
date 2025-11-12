#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long ans = 0;
void dfs(long long k,long long minn,long long now,long long sum){
    if(now == k){
        long long p = lower_bound(a+1,a+1+n,sum)-a;
        ans = ans+p-minn;
        ans = ans%998244353;
        return;
    }
    for(long long i = minn;i<=n;i++){
        dfs(k,i+1,now+1,sum+a[i]);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(long long i = 1;i<=n;i++){
        cin >> a[i];
    }
    int ts = 1;
    for(long long i = 1;i<=n;i++){
        if(a[i]!=1){
            ts = 0;
            break;
        }
    }
    if(ts && n >= 20){
        for(long long i = 3;i<=n;i++){
            long long z = min(i,n-i);
            long long up = 1;
            long long down = 1;
            for(long long j = 0;j<z;j++){
                up = up*(n-j);
                down = down*(j+1);
            }
            ans = ans+up/down;
            ans = ans%998244353;
        }
        cout << ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(long long i = 3;i<=n;i++){
        dfs(i,1,1,0);
    }
    cout << ans;
    return 0;
}
