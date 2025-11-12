#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
typedef pair<ll,ll> P;
const ll N = 2e5+15,Mod = 998244353;
ll read(){
    ll a = 1,ans = 0;
    char x = getchar();
    while(x < '0'||x > '9'){if(x=='-')a=-1;x=getchar();}
    while(x >= '0'&&x <= '9')ans = ans*10+x-'0',x = getchar();
    return ans*a;
}
char s[20];
ll c[20];
ll order[20],vis[20];
ll n,m;
ll ans = 0;
void dfs(ll x){
    if(x == n+1){
        ll cnt = 0;
        for(int i = 1;i <= n;i ++){
            if(s[i] == '0')cnt ++;
            else{
                if(cnt >= c[order[i]])cnt ++;
            }
        }
        if(cnt + m <= n)ans ++;
        return;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            vis[i] = 1;
            order[x] = i;
            dfs(x+1);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n = read(),m = read();
    scanf("%s",s+1);
    for(int i = 1;i <= n;i ++){
        c[i] = read();
    }
    dfs(1);
    cout<<ans;
    return 0;
}
