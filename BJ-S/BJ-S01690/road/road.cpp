#include<bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
struct yaq{
    int fr,to,val;
}e[1000001];
int n,m,k,x,y,z,t[100001],sum,a[11][10001],fa[100001],cnt[100001],p[100001],flag,res=1;
int found(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=found(fa[x]);
}
bool cmp(yaq a,yaq b){
    return a.val<b.val;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        e[res]=(yaq){x,y,z};
        res++;
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&t[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(e+1,e+res,cmp);
    for(int i=0,j=0;j<n-1;i++,j++){
        //printf("%d\n",i);
        //printf("%d %d %d\n",e[i].fr,e[i].to,e[i].val);
        //printf("%d %d\n",found(e[i].fr),found(e[i].to));
        if(found(e[i].fr)!=found(e[i].to)){
            fa[found(e[i].fr)]=found(e[i].to);
            //printf("%d %d %d\n",e[i].fr,e[i].to,e[i].val);
            sum+=e[i].val;
            p[j]=i;
        }else{
            j--;
        }
    }
    for(int i=0;i<n-1;i++){
        int tp=e[p[i]].val;
        for(int j=1;j<=k;j++){
            tp=min(tp,a[j][e[p[i]].fr]+a[j][e[p[i]].to]+t[j]);
        }
        sum-=e[p[i]].val-tp;
    }
    printf("%lld",sum);
    return 0;
}
