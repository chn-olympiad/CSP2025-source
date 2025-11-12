#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+2;
ll u[N],v[N],w[N];
ll n,m,k,sum;
struct js{
    ll u,v,w;
}r[N];
bool cmp(js x,js y){
    return x.w<y.w;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
    }
    sort(r+1,r+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum+=r[i].w;
    }
    cout << sum;
    return 0;
}
