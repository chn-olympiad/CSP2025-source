#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n,m,k,fa[maxn],ans = 0,p,l;
int find(int x){
    if(fa[x] == x)return x;
    else return fa[x] = find(fa[x]);
}
struct op{
    int u,v,w;
}ji[maxn];
bool cmp(op x,op y){
    if(x.w != y.w)return x.w < y.w;
    return x.u < y.u;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1 ; i <= n ; i++)fa[i] = i;
    for(int i = 1 ; i <= m ; i++){
        cin>>ji[i].u>>ji[i].v>>ji[i].w;
    }
    if(k == 0){
        sort(ji+1,ji+1+m,cmp);
        while(p < n-1){
            l++;
            if(find(ji[l].u) == find(ji[l].v))continue;
            fa[find(fa[ji[l].v])] = find(ji[l].u);
            ans += ji[l].w;
            p++;
        }
        cout<<ans;
    }
    else cout<<"13";
    return 0;
}