#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,f[10015],p,cnt,hd[100005],tl[100005],nxt[200005];
long long w,c[15],ans=1000000000000000000,sm,_;
struct node{
    int u,v;
    long long s,g;
}e[1000005],a[15][10005],nw[200005],ls[200005];
bool cmp(node _1,node _2){
    if(_1.s!=_2.s) return _1.s<_2.s;
    else return _1.g<_2.g;
}
void findr(int id){
    if(f[id]!=id){
        findr(f[id]);
        f[id]=f[f[id]];
    }
}
bool mg(int _1,int _2){
    findr(_1);
    findr(_2);
    if(f[_1]==f[_2]) return 0;
    else{
        f[f[_1]]=f[_2];
        return 1;
    }
}
void st(){
    for(int i = 0;i < 40000;i++) hd[i]=tl[i]=0;
    for(int i = 1;i <= cnt;i++){
        nxt[i]=0;
        _=nw[i].g;
        if(!hd[_]) hd[_]=tl[_]=i;
        else{
            nxt[tl[_]]=i;
            tl[_]=i;
        }
    }
    cnt=0;
    for(int i = 0;i < 40000;i++){
        for(int j = hd[i];j;j=nxt[j]){
            ls[++cnt]=nw[j];
        }
    }
    for(int i = 0;i < 40000;i++) hd[i]=tl[i]=0;
    for(int i = 1;i <= cnt;i++){
        nxt[i]=0;
        _=ls[i].s;
        if(!hd[_]) hd[_]=tl[_]=i;
        else{
            nxt[tl[_]]=i;
            tl[_]=i;
        }
    }
    cnt=0;
    for(int i = 0;i < 40000;i++){
        for(int j = hd[i];j;j=nxt[j]){
            nw[++cnt]=ls[j];
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v;
        cin >> w;
        e[i].s=w/40000;
        e[i].g=w%40000;
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> w;
            a[i][j].u=n+i;
            a[i][j].v=j;
            a[i][j].s=w/40000;
            a[i][j].g=w%40000;
        }
    }
    sort(e+1,e+m+1,cmp);
    for(int i = 1;i <= n;i++) f[i]=i;
    for(int i = 1;i <= m;i++){
        if(mg(e[i].u,e[i].v)) e[++p]=e[i];
    }
    for(int zt = 0;zt < (1<<k);zt++){
        cnt=sm=0;
        for(int i = 0;i < k;i++){
            if((zt>>i)&1){
                sm+=c[i+1];
                for(int j = 1;j <= n;j++){
                    nw[++cnt]=a[i+1][j];
                }
            }
        }
        for(int i = 1;i <= p;i++) nw[++cnt]=e[i];
        st();
        for(int i = 1;i <= n+k;i++) f[i]=i;
        for(int i = 1;i <= cnt;i++){
            if(mg(nw[i].u,nw[i].v)) sm+=nw[i].s*40000+nw[i].g;
        }
        ans=min(ans,sm);
//        cout << sm << "!\n";
    }
    cout << ans;
    return 0;
}