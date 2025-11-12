#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int K=15;
using ll=long long;
#define pllii pair<ll,pair<int,int>>
vector<pllii> e;
ll c[K],a[K][N];
pllii tmpe;
int n,m,k;
bool xc[N];
map<pair<int,int>,bool> xcv;
int fa[N];
int findfa(int x){
    while(fa[x]!=x)x=fa[x];
    return fa[x]=x;
}
void merge(int x,int y){
    int tx=findfa(x);
    int ty=findfa(y);
    fa[ty]=findfa(tx);
    return;
}
bool check(){
    int cur=findfa(1);
    for(int i=2;i<=n;i++){
        if(findfa(i)!=cur)return false;
    }
    return true;
}
ll csh(int u,int v){
    ll r=0;
    if(!xc[1]){xc[1]=true;r+=c[1];}
    if(!xcv.count({1,u})){xcv.insert({{1,u},true});r+=a[1][u];}
    if(!xcv.count({1,v})){xcv.insert({{1,v},true});r+=a[1][v];}
    return r;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&tmpe.second.first,&tmpe.second.second,&tmpe.first);
        e.push_back(tmpe);
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++)fa[i]=i;
    if(k==0){
        ll ans=0;
        for(auto ee:e){
            ll c=ee.first,uu=ee.second.first,vv=ee.second.second;
            merge(uu,vv);
            ans+=c;
            if(check())break;
        }
        printf("%lld",ans);
    }else if(k==1){
        ll ans=0;
        for(auto ee:e){
            ll c=ee.first,uu=ee.second.first,vv=ee.second.second;
            merge(uu,vv);
            ans+=min(c,csh(uu,vv));
            if(check())break;
        }
        printf("%lld",ans);
    }
    

    fclose(stdin);
    fclose(stdout);
    return 0;
}
