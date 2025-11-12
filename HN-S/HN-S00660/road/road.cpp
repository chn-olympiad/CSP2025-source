#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cnt,num,f[100010],t[21][100010];
int cc[20],nw,st[21],tp,el;
struct ed{
    int u,v,w;
    ed(int _u = 0,int _v = 0,int _w = 0){
        u = _u,v = _v,w = _w;
    }
    bool operator<(const ed &p)const{
        return v < p.v;
    }
}tt[100010],e[1000010],et[200010];
int fd(int x){
    if(x == f[x])return x;
    return f[x] = fd(f[x]);
}
inline int ca(int nn){
    int ans = 0;
    for(int i = 1;i <= n;++i)
        f[i] = i;
    for(int i = 1;i <= tp;++i)
        f[n + st[i]] = n + st[i];
    sort(e + 1,e + 1 + el);
    cnt = 1;
    for(int i = 1;i <= el;++i){
        ed y = e[i];
        int xx = fd(y.u),yy = fd(y.v);
        if(xx == yy)continue;
        ans += y.w;
        f[xx] = yy;
        ++cnt;
        if(cnt == nn)
            break;
    }
    return ans;
}
void dfs(int x){
    if(x == k + 1){
        for(int i = 1;i <= el;++i)
            et[i] = e[i];
        num = min(num,ca(n + tp) + nw);
        for(int i = 1;i <= el;++i)
            e[i] = et[i];
        return ;
    }
    dfs(x + 1);
    st[++tp] = x;
    nw += cc[x];
    for(int i = 1;i <= n;++i)
        e[++el] = ed(n + x,i,t[x][i]);
    dfs(x + 1);
    nw -= cc[x];
    el -= n;
    --tp;
    return ;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i <= m;++i){
        int x,y,z;
        cin>>x>>y>>z;
        e[++el] = ed(x,y,z);
    }
    for(int i = 1;i <= n;++i)
        f[i] = i;
    sort(e + 1,e + 1 + el);
    cnt = 1;
    for(int i = 1;i <= el;++i){
        ed y = e[i];
        int xx = fd(y.u),yy = fd(y.v);
        if(xx == yy)continue;
        num += y.w;
        f[xx] = yy;
        tt[++tp] = y;
        ++cnt;
        if(cnt == n)
            break;
    }
    el = tp;
    while(tp){
        e[tp] = tt[tp];
        tp--;
    }
    for(int i = 1;i <= k;++i){
        cin>>cc[i];
        for(int j = 1;j <= n;++j)
            cin>>t[i][j];
    }
    nw = 0;
    dfs(1);
    cout<<num;
    return 0;
}