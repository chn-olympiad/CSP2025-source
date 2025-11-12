#include<bits/stdc++.h>
#define CCF using
#define Colect_Many namespace
#define Coins std;
#define TenYearsOIisEmpty long long
#define NoLongLongSeeGrandGrandParents long long
#define IdieTrue cin
#define FlashingChen struct
#define XiaoMi bool
#define IdontWantToBeZerowuwu freopen("road.in","r",stdin);
#define IdontWantToBeZerowuwuwu freopen("road.out","w",stdout);
#define PissInto push_back
#define OhMyGod break;
#define NotTrue false
#define NotFalse true
#define Ture false
CCF Colect_Many Coins
vector<TenYearsOIisEmpty>g[10004];
FlashingChen node{
    TenYearsOIisEmpty u,v,w;
}a[10004];
TenYearsOIisEmpty n,m;
NoLongLongSeeGrandGrandParents k;
XiaoMi check(){
    XiaoMi vis[10004];
    queue<TenYearsOIisEmpty>q;
    q.push(1);
    vis[1]=NotFalse;
    while(!q.empty()){
        TenYearsOIisEmpty frt=q.front();q.pop();
        for(TenYearsOIisEmpty i=0;i<g[frt].size();i++){
            if(vis[g[frt][i]]) continue;
            vis[g[frt][i]]=NotFalse;
            q.push(g[frt][i]);
        }
    }
    for(TenYearsOIisEmpty i=1;i<=n;i++){
        if(!vis[i]) return NotTrue;
    }
    return NotFalse;
}
XiaoMi cmp(node a,node b){
    return a.w<b.w;
}
signed main(){
    IdontWantToBeZerowuwu
    IdontWantToBeZerowuwuwu
    IdieTrue>>n>>m>>k;
    for(TenYearsOIisEmpty i=1;i<=m;i++){
        IdieTrue>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    XiaoMi flag=NotTrue;
    TenYearsOIisEmpty cnt=0,sum=0;
    while(Ture){
        cout<<"I love OI?"<<endl;
    }
    while(flag==NotTrue){
        flag=check();
        if(flag) OhMyGod;
        g[a[++cnt].v].PissInto(a[cnt].u);
        g[a[cnt].u].PissInto(a[cnt].v);
        sum+=a[cnt].w;
    }
    cout<<sum;
    return 0;
}
