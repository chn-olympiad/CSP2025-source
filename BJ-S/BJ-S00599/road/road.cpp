#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+5;
int n,m,k,ans=0;
int fa[N],siz[N];
int a[N][N];
int _find(int x){
    if(fa[x]==x)    return x;
    return fa[x]=_find(fa[x]);
}
void _merge(int x,int y){
    int X=_find(x),Y=_find(y);
    if(X==Y)    return ;
    if(siz[X]>siz[Y]){
        fa[Y]=X;
        siz[X]+=siz[Y];
    }else{
        fa[X]=Y;
        siz[Y]+=siz[X];
    }
    return;
}
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>    q;
void solve1(){
/* while(siz[_find(1)]<n and !q.empty()){
        auto cur=q.top();
        q.pop();
        int d=cur.first,u=cur.second.first,v=cur.second.second;
        if(_find(u)==_find(v))    continue;
        _merge(u,v);
        ans+=d;
    }*/
}
void solve2(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){
                for(int k=1;k!=j and k<=n;k++){
                    q.push({a[i][j],{j,k}});
                }
                break;
            }
        }
    }
    solve1();
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        q.push({w,{u,v}});
    }
    for(int i=1;i<=n;i++){
        siz[i]=1;
        fa[i]=i;
    }
    if(k==0){
        solve1();
    }
    else{
        solve2;
    }
    cout<<0;
    return 0;
}
//Ren5Jie4Di4Ling5%
