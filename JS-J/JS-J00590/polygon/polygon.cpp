#include<bits/stdc++.h>
using namespace std;

long long x;
long long sum = 0;
long long a[50005];
long long ans[50005];
long long mp[50005];
bool flag[50005];

void dfs(long long n,long long r,long long k){
    if(k > r){
        if(r<3){
            return;
        }
        bool f = true;
        for(long long i = 1;i<r;i++){
            if(ans[i]>ans[i+1]||ans[i] == ans[i+1]){
                f = false;
            }
        }
        if(f){
            long long cnt = 0;
            long long maxx = INT_MIN;
            for(long long i = 1;i<=r;i++){
                maxx = max(a[ans[i]], maxx);
                cnt+=a[ans[i]];
            }
            if(cnt > maxx*2){
                sum++;
            }
        }
        return;
    }
    for(long long i = 1;i<=n;i++){
        ans[k] += i;
        dfs(n, r, k+1);
        ans[k] = 0;
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> x;
    for(long long i = 1;i<=x;i++){
        cin >> a[i];
    }
    for(long long i = 1;i<=x;i++){
        dfs(x, i, 1);
    }
    cout << sum%998244353;
    return 0;
}
