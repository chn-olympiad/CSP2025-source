#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int R = 10000010;
ll a[R];
ll f(ll x){
    if(a[x] == x){
        return x;
    }else{
        return a[x] = f(a[x]);
    }
}

void update(ll x,ll y){
    a[f(x)] = f(y);
    return;
}

struct edge{
    ll u,v,dis;
}e[R];

bool cmp(edge xx,edge yy){
    return xx.dis < yy.dis;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);


    ll n,m,k,cj;
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++){
        cin>>e[i].u>>e[i].v>>e[i].dis;
    }
    for(int i = 1;i <= n;i++){
        a[i] = i;
    }
    for(int i = 1;i <= k;i++){
        ll c;
        cin>>c;
        ll x;
        for(int j = 1;j <= n;j++){
            cin>>x;
        }
    }
    sort(e+1,e+m+1,cmp);
    int ans = 0,cnt = 0;
    for(int i = 1;i <= n;i++){
        if(cnt >= n-1)break;
        if(f(e[i].u) != f(e[i].v)){
            cnt++;
            update(e[i].u,e[i].v);
            ans += e[i].dis;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
