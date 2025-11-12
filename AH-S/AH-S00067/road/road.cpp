#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<iomanip>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<stack>
#define ll long long
using namespace std;
ll n,m,k;
struct edge{
    ll bt,ed,w;
    bool zz;
}pos[2000005],repos[2000005];
ll lpos[15],rpos[15];
ll p[15],x[10005];
ll fa[10005];
ll final_answer;
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    return ;
}
ll find(ll x){
    if(x==fa[x])    return x;
    return fa[x]=find(fa[x]);
}
void unite(ll u,ll v){
    u=find(u);
    v=find(v);
    if(u==v)    return ;
    fa[u]=v;
    return ;
}
bool same(ll u,ll v){
    return find(u)==find(v);
}
bool cmp(edge u,edge v){
    if(v.zz!=u.zz)  return u.zz==1;
    return u.w<v.w;
}
bool posu[15];
ll cnt;
bool fk;
void dfs(ll id){
    if(id==k+1){
        ll ans=0;
        for(int i=1;i<=cnt;i++){
            repos[i]=pos[i];
        }
        for(int i=1;i<=k;i++){
            if(posu[i]==1){
                ans+=p[i];
                for(int j=lpos[i];j<=rpos[i];j++){
                    repos[j].zz=1;
                }
            }
        }
        init();
        sort(repos+1,repos+1+cnt,cmp);
        for(int i=1;i<=cnt;i++){
            if(repos[i].zz==0)  continue;
            if(!same(repos[i].bt,repos[i].ed)){
                unite(repos[i].bt,repos[i].ed);
                ans+=repos[i].w;
            }
        }
        if(final_answer==0) final_answer=ans;
        final_answer=min(final_answer,ans);
        return ;
    }
    posu[id]=true;
    dfs(id+1);
    posu[id]=false;
    dfs(id+1);
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        pos[++cnt]={x,y,z,1};
    }
    for(int i=1;i<=k;i++){
        cin>>p[i];
        if(p[i]!=0) fk=true;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        lpos[i]=cnt+1;
        for(int j=1;j<=n;j++){
            for(int k1=j+1;k1<=n;k1++){
                pos[++cnt]={j,k1,x[j]+x[k1],0};
            }
        }
        rpos[i]=cnt;
    }
    if(fk==0){
        ll ans=0;
        for(int i=1;i<=cnt;i++){
            repos[i]=pos[i];
            repos[i].zz=1;
        }
        init();
        sort(repos+1,repos+1+cnt,cmp);
        for(int i=1;i<=cnt;i++){
            if(repos[i].zz==0)  continue;
            if(!same(repos[i].bt,repos[i].ed)){
                unite(repos[i].bt,repos[i].ed);
                ans+=repos[i].w;
            }
        }
        cout<<ans;
        return 0;
    }
    dfs(1);
    cout<<final_answer;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
