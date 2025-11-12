#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10],a[1000001],g[1000001],s=0,t=0;
struct aa{
    int u,v,w;
}qwq[1000001];
int find(int x){
    if(g[x]==x){
        return x;
    }else{
        return g[x]=find(g[x]);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        g[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>qwq[i].u>>qwq[i].v>>qwq[i].w;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(qwq[j].w>qwq[j+1].w)swap(qwq[j],qwq[j+1]);
        }
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
                cin>>a[j];
        }
    }
    for(int i=0;t<n;i++){
        int gx=qwq[i].u,gy=qwq[i].v;
        if(find(gx)==find(gy)){
            continue;
        }
        g[gx]=g[gy];
        t++;
        s+=qwq[i].w;
    }
    cout<<s;
    return 0;
}
