#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , k , cnt , ans;
ll fa[11010];
struct node{
    ll u , v , z;
    bool neww;
    void Scanf(){
        scanf("%lld%lld%lld" , &u , &v , &z);
        return ;
    }
    bool operator < (const node& x) const{
        return z < x.z;
    }
}street[10000010];
ll cost[1010];
ll Find(ll x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = Find(fa[x]);
}
void kruskal(){
    ll u , v , z;
    for(int i = 1;i <= m;i++){
        u = Find(street[i].u);
        v = Find(street[i].v);
        if(u == v){
            continue;
        }
        if(street[i].neww == false){
            n++;
        }
        ans += street[i].z;
        fa[u] = v;
        cnt++;
        if(cnt == n - 1){
            break;
        }
    }
}
int main(){
    
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    
    
    cin >> n >> m >> k;
    for(int i = 0;i <= n + k + 1;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++){
        street[i].Scanf();
        street[i].neww = true;
    }
    for(int i = 1;i <= k;i++){
        cin >> cost[i];
        for(int j = 0;j < n;j++){
            ll z;
            cin >> z;
            m++;
            street[m].u = n+i;
            street[m].v = j+1;
            street[m].z = z;
            street[m].neww = false;
        }
    }
    sort(street+1 , street+m+1);
    kruskal();
    cout << ans;

    return 0;
}
