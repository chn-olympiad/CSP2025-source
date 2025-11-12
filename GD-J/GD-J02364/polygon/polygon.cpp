//WTX
#include <iostream>
#include <cstring>
using namespace std;
#define MOD 998244353
int ans[5005];
int n;
int a[5005];
bool vis[5005];
int qrq(int k){
    int ans = 1;
    for (int i = 2;i<=k;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans%MOD;
}
void dfs(int dep,int mdep,int maxn,int sm){
    if (dep==mdep&&(sm-maxn>maxn)){
        ans[dep]++;
        ans[dep]%=MOD;
    }
    for (int i = 1;i<=n;i++){
        if (!vis[i]){
            vis[i]=1;
            dfs(dep+1,mdep,max(maxn,a[i]),sm+a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for (int i = 3;i<=n;i++){
        memset(vis,0,sizeof vis);
        dfs(0,i,0,0);
    }
    int anss = 0;
    for (int i = 3;i<=n;i++){
        anss+=ans[i]/(qrq(i));
        anss%=MOD;
    }
    cout << anss;
}