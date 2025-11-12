#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
int n,m,k,sub1,sub2,fa[10001];
long long ans;
vector<node>e[10001];
struct edge{
    int fr,to,c;
}a[1000001];
int x[11][10001],xc[11];
int ft(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=ft(fa[x]);
}
bool uni(int x,int y){
    int fx=ft(x),fy=ft(y);
    if(fx==fy)return 0;
    else fa[fx]=fy;
    return 1;
}
bool operator <(edge a,edge b){
    if(a.c==b.c&&a.fr==b.fr)return a.to<b.to;
    if(a.c==b.c)return a.fr<b.fr;
    return a.c<b.c;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)sub1=1;
    if(!sub1)sub2=1;
    for(int i=1;i<=m;i++){
        cin>>a[i].fr>>a[i].to>>a[i].c;
        e[a[i].fr].push_back({a[i].to,a[i].c});
        e[a[i].to].push_back({a[i].fr,a[i].c});
    }
    for(int i=1;i<=k;i++){
        cin>>xc[i];
        if(xc[i]!=0)sub2=0;
        for(int j=1;j<=n;j++){
            cin>>x[i][j];
            if(x[i][j]!=0)sub2=0;
        }
    }
    if(sub2){
        cout<<0;
        return 0;
    }
    if(sub1){
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++){
            if(uni(a[i].fr,a[i].to)){
                ans+=a[i].c;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
/*
5 7 0
1 2 2
2 3 1
3 1 3
3 4 4
1 4 10
3 5 5
5 4 3
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0
*/
