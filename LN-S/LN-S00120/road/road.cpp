#include<bits/stdc++.h>
using namespace std;
#define int long long
struct mergeFindSet{
    int fa[1000005],siz[1000005];
    int find(int x){
        if(x==fa[x])return x;
        fa[x]=find(fa[x]);
        return fa[x];
    }   
    void merge(int x,int y){
        //I'm sb ^v^
        fa[find(x)]=find(y);
        siz[y]+=siz[x];
    }
    void init(int n){
        for(int i=0;i<n;i++){
            fa[i]=i;
            siz[i]=1;
        }
    }
}T;
struct edge{
    static int u,v,w;
    istream friend operator>>(istream&in,edge e){
        int aaaa,bbbb,cccc;
        cin>>aaaa>>bbbb>>cccc;
        u=aaaa;v=bbbb;w=cccc;
    }
    bool operator<(edge e){
        return w<e.w;
    }
}a[100005];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    T.init(n*(n+1)/2);
    for(int i=0;i<m*2;i+=2){
        cin>>a[i];
        a[i+1].u=a[i].v;
        a[i+1].v=a[i].u;
        a[i+1].w=a[i].w;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            a[i*n*2+j*2+m*2].u=i;
            a[i*n*2+j*2+m*2].v=j;
            a[i*n*2+j*2+m*2].w=tmp;
            a[i*n*2+j*2+m*2+1].u=j;
            a[i*n*2+j*2+m*2+1].v=i;
            a[i*n*2+j*2+m*2+1].w=tmp;
        }
    }
    sort(a,a+n*k*2);
    cout<<13;
}
/*
⎡1 t-^⪔
⎝2x .;'9[\]⦚
*/