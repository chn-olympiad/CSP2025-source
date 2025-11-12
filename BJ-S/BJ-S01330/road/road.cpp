#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[10009];
int sz[10009];
int n;
int getfa(int t){
    if(t==fa[t]){
        return t;
    }
    return fa[t]=getfa(fa[t]);
}
void merge(int u,int v){
    u=getfa(u),v=getfa(v);
    if(sz[u]>sz[v]){
        swap(u,v);
    }
    fa[v]=u;
}
void clear(){
    for(int i=1;i<=n;i++){
        fa[i]=i,sz[i]=1;
    }
}
struct st{
    int u,v,w;
}aa[1200009];
bool cmp(st a1,st a2){
    return a1.w<a2.w;
}
struct vil{
    int w[10009];
    int c;
    int mi;
}a[19];
struct cc{
    int u,v,w,o;
}z[200009];
bool cp(cc a1,cc a2){
    return a1.w<a2.w;
}
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>aa[i].u>>aa[i].v>>aa[i].w;
    }
    int inn;
    inn=0;
    for(int i=1;i<=k;i++){
        cin>>a[i].c;
        a[i].mi=1;
        for(int j=1;j<=n;j++){
            cin>>a[i].w[j];
            if(a[i].w[j]<a[i].w[a[i].mi]){
                a[i].mi=j;
            }
        }
        if(a[i].w[a[i].mi]==0&&a[i].c==0){
            for(int j=1;j<=n;j++){
                if(j!=a[i].mi){
                    aa[++m]={a[i].mi,j,a[i].w[j]};
                }
            }
        }else{
            a[++inn]=a[i];
        }

    }
    k=inn;
    inn=0;
    sort(aa+1,aa+1+m,cmp);
    clear();
    for(int i=1;i<=m;i++){
        if(getfa(aa[i].u)!=getfa(aa[i].v)){
            z[++inn]={aa[i].u,aa[i].v,aa[i].w,0ll};
            merge(aa[i].u,aa[i].v);
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
                if(j!=a[i].mi)
            z[++inn]={a[i].mi,j,a[i].w[j],i};
        }
    }
    sort(z+1,z+1+inn,cp);
    //cout<<inn<<endl;
    int sum;
    sum=1e16;
    for(int i=0;i<(1ll<<k);i++){
        clear();
        int ans;
        ans=0;
        for(int j=1;j<=k;j++){
            if(i&(1ll<<(j-1))){
               ans+=a[j].c+a[j].w[a[j].mi];
            }
        }
        //cout<<ans<<" ";
        int c;
        c=1;
        for(int j=1;j<=inn;j++){
                if(z[j].o&&!((1ll<<z[j].o-1)&i)){
                    continue;
                }
            if(getfa(z[j].u)!=getfa(z[j].v)){
                ans+=z[j].w;
                c++;
                if(c==n){
                    break;
                }
                merge(z[j].u,z[j].v);
            }
        }
        //cout<<ans<<endl;
        sum=min(sum,ans);
    }
    cout<<sum<<endl;
    return 0;
}
