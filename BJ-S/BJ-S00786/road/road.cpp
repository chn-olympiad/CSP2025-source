#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll u;
    ll v;
    ll w;
}e[10000001];
int fa[1005];
int c[1005];
ll a[15][1005];
int cu[1000001];
int cv[1000001];
ll cw[1000001];
int n = 0,m = 0,k = 0;
int findx(int x){
    while(x != fa[x]){
        x = fa[x];
    }
    return x;
}
bool cmp(node x,node y){
    return x.w < y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++)
    {
        cin>>cu[i]>>cv[i]>>cw[i];
    }
    for(int i = 1;i <= k;i++){
        cin>>c[i];
        for(int j = 1;j <= n;j++){
            cin>>a[i][j];
        }
    }
    int cm = m;
    int cn = n;
    ll ans = 1e18;
    for(int mask = 0;mask <= (1 << k);mask++)
    {

        m = cm;
        ll sum = 0;
        n = cn;
        for(int i = 1;i <= m;i++){
            e[i].u = cu[i];
            e[i].v = cv[i];
            e[i].w = cw[i];
        }
        for(int i = 1;i <= k;i++){ //shiofujianli
            if((mask & (1 << (i - 1)))){
                n++;
                sum += c[i];
                for(int j = 1;j <= n;j++){
                    e[++m].u = n;
                    e[m].v = j;
                    e[m].w = a[i][j];
                }
            }
        }
        for(int i = 1;i <= n;i++) fa[i] = i;
        sort(e + 1,e + m + 1,cmp);
        int cnt = 0;
        for(int i = 1;i <= m;i++){
            int u = findx(e[i].u);
            int v = findx(e[i].v);
            if(u != v){
                fa[u] = v;
                cnt++;
                sum += e[i].w;
            }
            if(cnt == n - 1) break;
        }
        ans = min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
