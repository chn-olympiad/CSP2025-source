#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],nwk;
bool f[15];
long long ans=0x3f3f3f3f3f3f3f3f,cnt;
struct node{
    int frm,to,weight,depend;
}a[1100010];
int father[10020];
bool cmp(node x,node y){
    return x.weight<y.weight;
}
void init(){
    for(int i=1;i<=n+k;i++)
        father[i]=i;
}
int findfather(int x){
    if(x==father[x])
        return x;
    father[x]=findfather(father[x]);
    return father[x];
}
int t,fatherx,fathery,margenumber,fullnode;
void solve(){
    init();
    fullnode=n+nwk;
    margenumber=1;
    for(int i=1;i<=t;i++){
        if(f[a[i].depend]==0)
            continue;
        fatherx=findfather(a[i].frm);
        fathery=findfather(a[i].to);
        if(fatherx==fathery)
            continue;
        cnt+=a[i].weight;
        father[fatherx]=father[fathery];
        margenumber++;
        if(margenumber==fullnode)
            break;
    }
    ans=min(ans,cnt);
    return;
}
void dfs(int nw){
    if(nw>k){
        cnt=nwk=0;
        for(int i=1;i<=k;i++)
            if(f[i]){
                nwk++;
                cnt+=c[i];
            }
        solve();
        return;
    }
    f[nw]=1;
    dfs(nw+1);
    f[nw]=0;
    dfs(nw+1);
    return;
}
int temp,temp2;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    t=m+n*k;
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&a[i].frm,&a[i].to,&a[i].weight);
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&temp);
            temp2=m+(i-1)*n+j;
            a[temp2].frm=n+i;//the country i is node(n+i)
            a[temp2].to=j;
            a[temp2].weight=temp;
            a[temp2].depend=i;//citys' depend equals to 0
        }
    }
    sort(a+1,a+1+m+n*k,cmp);
    f[0]=1;
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
