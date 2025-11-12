#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[5010];
long long ans = 0;
long long mod = 998244353;
int vis[5010];

void dfs(long long e, long long num, long long ni, long long t){

    if (num == e+1){
        if (t > a[ni-1]*2){
            //for (int i = 1; i <= n; i++){
            //    if (vis[i] == 1) cout << a[i] << " ";
            //}
            //cout << endl;
            ans++;
            ans%=mod;
            return;
        }
    }

    for (int i = ni; i <= n; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            dfs(e,num+1,i+1,t+a[i]);
            vis[i] = 0;
        }
        if (num == e){
            if (t+a[i] <= a[i]*2){
                return;
            }
        }
    }

}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    //long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);

    for (long long i = 3; i <= n; i++){
        memset(vis,0,sizeof vis);
        dfs(i,1,1,0);
    }

    cout << ans;


    return 0;
}
