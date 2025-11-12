#include <bits/stdc++.h>
using namespace std;
const long long N = 6000;
const long long MOD = 998244353;
long long n;
long long a[N];
long long maxn = -N;
long long t[N];
long long ans;
bool vis[N];
long long te[N];
long long te2[N];
map<long long,bool> mp;
long long C(long long n,long long x){
    long long temp = 1;
    long long cnt = 2;
    for(long long i = n;i>=n-x+1;i--){
        temp *= i;
        while(temp % cnt == 0 && cnt <= x){
            temp /= cnt;
            cnt++;
        }
    }
    return temp%MOD;
}
void dfs(long long cnt,long long k){
    for(long long i = 1;i<=n;i++){
        if(vis[i] == false){
            t[cnt] = a[i];
            vis[i] = true;
        }
        long long sum = 0;
        long long maxn = -N;
        if(cnt == k){
            long long m = 0;
            memset(te,0,sizeof(te));
            sort(t+1,t+1+cnt);
            for(long long i = 1;i<=cnt;i++){
                sum += t[i];
                maxn = max(maxn,t[i]);
                m += t[i] * (i+N);
                te[t[i]]++;
            }
            bool flag = true;
            for(long long i = 1;i<=maxn;i++){
                if(te[i] > te2[i]){
                    flag = false;
                }
            }
            if(sum > maxn * 2 && mp[m] == false && flag == true){
                ans++;
                mp[m] = true;
            }
            return ;
        }
        dfs(cnt+1,k);
        vis[i] = false;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
        te2[a[i]]++;
        maxn = max(maxn,a[i]);
    }
    if(maxn == 1){
        for(long long i = 3;i<=n;i++){
            ans += C(n,i);
            ans %= MOD;
        }
        cout<<ans%MOD;
    }else if(n == 3){
        long long maxn = max(a[1],max(a[2],a[3]));
        long long sum = a[1]+a[2]+a[3];
        if(sum > 2*maxn){
            ans++;
        }
        cout<<ans;
    }else if(n <= 20){
        for(long long i = 3;i<=n;i++){
            memset(vis,false,sizeof(vis));
            dfs(1,i);
        }
        cout<<ans;
    }
    return 0;
}
