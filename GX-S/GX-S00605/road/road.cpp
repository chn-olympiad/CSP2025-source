#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll N = 1e5+15;
ll read(){
    ll a = 1,ans = 0;
    char x = getchar();
    while(x < '0'||x > '9'){if(x=='-')a=-1;x=getchar();}
    while(x >= '0'&&x <= '9')ans = ans*10+x-'0',x = getchar();
    return ans*a;
}
pair<ll,P> G[N];
priority_queue<pair<ll,P> > q;
ll f[N];
ll find(ll x){
    return x == f[x]?x:f[x] = find(f[x]);
}
ll c[15],a[15][N];
void work(){
    ll n = read(),m = read(),k = read();
    for(int i = 1;i <= n+k;i ++)f[i] = i;
    for(int i = 1;i <= m;i ++){
        ll x = read(),y = read(),z = read();
        q.push(make_pair(-z,make_pair(x,y)));
    }
    ll cnt = 0,ans = 0;
    while(cnt != n-1){
        pair<ll, P> e = q.top();q.pop();
        ll x = e.second.first,y = e.second.second;
        if(find(x) != find(y)){
            cnt ++;
            ans -= e.first;
            f[find(x)] = find(y);
            G[cnt] = e;
        }
    }
    for(int i = 1;i <= k;i ++){
        c[i] = read();
        for(int j = 1;j <= n;j ++)a[i][j] = read();
    }
    for(int stat = 1;stat < (1<<k);stat ++){
        while(q.size())q.pop();
        for(int i = 1;i <= n+k;i ++)f[i] = i;
        for(int i = 1;i < n;i ++){
            q.push(G[i]);
        }
        ll ppc = 0,tmp = 0;
        for(int i = 1;i <= k;i ++){
            if(stat & (1<<i-1)){
                ppc ++;tmp += c[i];
                for(int j = 1;j <= n;j ++){
                    q.push(make_pair(-a[i][j],make_pair(i+n,j)));
                }
            }
        }
        cnt = 0;
        while(q.size()&&cnt < n+ppc-1){
            pair<ll, P> e = q.top();q.pop();
            ll x = e.second.first,y = e.second.second;
            if(find(x) != find(y)){
                cnt ++;
                tmp -= e.first;
                f[find(x)] = find(y);
            }
        }
        ans = min(ans,tmp);
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll T = 1;
    while(T--)work();
    return 0;
}
