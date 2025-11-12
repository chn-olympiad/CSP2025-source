#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+5;
int fa[maxn];
int n,m,k,ans;
struct node{
    int u,v,w;
    bool operator<(const node &x)const{
        return w<x.w;
    }
};
vector<node> mp;
int get_fa(int x){
    return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
/*
void solve(){
    for(int i=0;i<(1<<5);i++){
        for(int j=0;j<5;j++){
            if(i&(1<<j)){
                ans+=c[j+1];
            }
        }
    }
}
*/
signed main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp.push_back({u,v,w});
    }
    if(k==0){
        sort(mp.begin(),mp.end());
        for(int i=0;i<mp.size();i++){
            int u=mp[i].u,v=mp[i].v,w=mp[i].w;
            int uu=get_fa(u);
            int vv=get_fa(v);
            if(uu==vv) continue;
            fa[uu]=vv,ans+=w,n--;
            if(n<=1) break;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        for(int j=1;j<=n;j++){
            int k;
            cin>>k;
            mp.push_back({i,j,x+k});
        }
    }
    sort(mp.begin(),mp.end());
    for(int i=0;i<mp.size();i++){
        int u=mp[i].u,v=mp[i].v,w=mp[i].w;
        int uu=get_fa(u);
        int vv=get_fa(v);
        if(uu==vv) continue;
        fa[uu]=vv,ans+=w,n--;
        if(n<=1) break;
    }
    cout<<ans;
    return 0;
}
