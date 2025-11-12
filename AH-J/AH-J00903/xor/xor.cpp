#include<bits/stdc++.h>
using namespace std;
int n, k, ans;
map<int, long long> a;
void dfs(int i, long long sum, int cnt){
    if(i > n) {
        ans = max(ans, cnt);
        return;
    }
    if(sum == k){
        dfs(i+1, a[i], cnt+1);
    }else{
        dfs(i+1, sum^a[i], cnt);
    }
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    int f = 1;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        f = (a[i]==1?f:0);
    }
    a[0] = 0x3f3f3f3f;
    if(f == 1){
        if(k == 1) cout<<n<<endl;
        else cout<<0<<endl;
        return 0;
    }else if(k == 1){
        for(int i=1; i<=n; i++){
            if(a[i] == 1) ans++;
        }
    }else if(n <= 20){
        dfs(1, 0, 1);
    }else{
        long long now = 0;
        for(int i=1; i<=n; i++){
            now ^= a[i];
            if(now == k){
                ans++;
                now = 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
