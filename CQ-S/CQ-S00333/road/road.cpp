#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+5,M=2e6+5;
ll n,m,k,cnt,c[N],ans,a[15][N];
struct edge{
    ll u,v,w;
}ed[M];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
namespace DSU{
    int s[N],siz[N];
    void init(int len){
        for(int i=1;i<=len;i++){
            s[i]=i;
            siz[i]=1;
        }
    }
    int find_set(int x){return s[x]==x?x:(s[x]=find_set(s[x]));}
    void merge_set(int x,int y){
        x=find_set(x);y=find_set(y);
        if(x==y)return;
        if(siz[x]>siz[y])swap(x,y);
        s[x]=y;siz[y]+=siz[x];
    }
}using namespace DSU;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    }
    cnt=m;
    bool f=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0)f=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(!f){
        for(int i=1;i<=k;i++){
            int pos=0;
            for(int j=1;j<=n;j++){
                if(a[i][j]==0)pos=j;
            }
            for(int j=1;j<=n;j++){
                if(j==pos)continue;
                ed[++cnt].u=pos;ed[cnt].v=j;ed[cnt].w=a[i][j];
            }
        }
        sort(ed+1,ed+cnt+1,cmp);
        init(n);
        for(int i=1;i<=cnt;i++){
            if(find_set(ed[i].u)!=find_set(ed[i].v)){
                merge_set(ed[i].u,ed[i].v);
                ans+=ed[i].w;
            }
        }
        cout<<ans;
        return 0;
    }
    if(k==0){
        sort(ed+1,ed+m+1,cmp);
        init(n);
        for(int i=1;i<=m;i++){
            if(find_set(ed[i].u)!=find_set(ed[i].v)){
                merge_set(ed[i].u,ed[i].v);
                ans+=ed[i].w;
            }
        }
        cout<<ans;
        return 0;
    }
    // for(int i=1;i<)
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4


4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 10 10 10 10

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

g++ Untitled-1.cpp -o Untitled-1.exe -std=c++14 -O2 -Wl,--stack=1000000000
g++ road.cpp -o road.exe -std=c++14 -O2 -Wl,--stack=1000000000
*/