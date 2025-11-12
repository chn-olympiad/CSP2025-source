#include <bits/stdc++.h>
#define il inline
#define rg register
#define prev my_prev
using namespace std;
using ll = long long;
const int mod = 998'244'353;
int n,ans,a[5050],prev[5050];
int c[5050][5050];
il ll pow(int x){
    ll base = 2;
    ll res = 1;
    while(x){
        if(x&1) res = (res*base)%mod;
        base=(base*base)%mod;
        x>>=1;
    }
    return res;
}
il void dfs(int sum,int maxx,int idx,int choose){
    if(idx+choose<3) return ;
    if(idx<0) return ;
    if(sum+prev[idx]<=maxx*2) return ;
    if(sum>maxx*2 && choose>=3){
        ans = (ans+pow(idx))%mod;
        return ;
    }
    dfs(sum+a[idx],max(maxx,a[idx]),idx-1,choose+1);
    dfs(sum,maxx,idx-1,choose);
}
int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //cerr << pow(30);
    scanf("%d",&n);
    bool flag = 1;
    for(rg int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i] != 1) flag = 0;
    }
    if(flag){
        c[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=i;j++){
                c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
                cerr << c[i][j]<<' ';
            }
        }
        for(int i = 3;i<=n;i++) ans = (ans+c[n][i])%mod;
        printf("%d",ans);
        return 0;
    }
    sort(a+1,a+1+n);
    for(rg int i = 1;i<=n;i++) prev[i] = prev[i-1]+a[i];
    dfs(0,0,n,0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
