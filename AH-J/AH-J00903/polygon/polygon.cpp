#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n, ans, a[5010];
map<long long, int> t;
void dfs(int i, long long maxn, long long sum, int cnt){
    if(sum > 2*maxn && cnt >= 3){
        ans++;
        ans %= mod;
    }else{
        if(i > n) return;
        dfs(i+1, maxn, sum, cnt);//不选
    }
    if(i > n) return;
    dfs(i+1, max(maxn, a[i]), sum+a[i], cnt+1);//选
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        t[a[i]]=1;
    }
    sort(a+1, a+1+n);
    if(n<=20) dfs(1, 0, 0, 0);
    else{
        long long last = 0;
        for(auto it=t.begin(); it!=t.end(); it++){
            long long maxn = it->first, sum = 0, temp;
            for(int i=1; i<=n; i++){
                maxn = max(maxn, a[i]);
                sum += a[i];
                if(sum > maxn*2){
                    temp = (ans + n-i+1)%mod;
                    break;
                }
            }
            if(maxn != last){
                ans = (ans+temp)%mod;
            }
            last = maxn;
        }
    }
    cout<<ans<<endl;
    return 0;
}
