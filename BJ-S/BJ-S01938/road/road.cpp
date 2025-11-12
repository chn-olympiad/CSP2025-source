#include<bits/stdc++.h>
using namespace std;
int T;
struct Edge{
    int point;
    int next;
    int sizee;
}a [1000005];
int fa[10005];
struct aEdge{
    int sizee;
    int kr[1000005];
}kc[11];
int n,m,k,ans;
bool cmp(Edge a,Edge b){
    return a.sizee<b.sizee;
}
int find(int x){
    return fa[x];
}
inline void kru(){
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(find(a[i].point)==find(a[i].next)) continue;
        ans+=a[i].sizee;
        fa[a[i].point] = fa[a[i].next]; 

    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].point>>a[i].next>>a[i].sizee;
    }
    for(int i=1;i<=k;i++){
        cin>>kc[i].sizee;
        for(int j=1;j<=n;j++){
            cin>>kc[i].kr[j];
        }
    }
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
    kru();

    cout<<ans;
    return 0;
}
