#include<bits/stdc++.h>
using namespace std;
struct edge{int from,to,val;};
bool operator <(edge x,edge y){return x.val<y.val;}
int fa[10015],n,m,siz[10015];
void init(){
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return 0;
    if(siz[x]>siz[y]) swap(x,y);
    siz[y]+=siz[x];
    fa[x]=y;
    return 1;
}
#define MST vector<edge> 
// struct test{
//     edge lf[10015];
// }bqr[1<<10];
MST a[1<<10];
MST get_mst(vector<edge> E){
    MST ret;
    init();
    for(auto u:E){
        int x=u.from,y=u.to,z=u.val;
        if(merge(x,y)){
            ret.push_back(u);
        }
    }return ret;
}
MST merge_sort(MST A,MST B){
    int i=0,j=0;MST ret;
    while(i<A.size()&&j<B.size()){
        if(A[i]<B[j]) ret.push_back(A[i]),i++;
        else ret.push_back(B[j]),j++;
    }
    while(i<A.size()){
        ret.push_back(A[i]),i++;
    }
    while(j<B.size()){
        ret.push_back(B[j]),j++;
    }return ret;
}
long long ys(MST A){
    long long ret=0;for(auto u:A) ret+=u.val;
    return ret;
}
int c[4587];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int k;cin>>k;
    n+=k;
    vector<edge> fir;
    while(m--){
        int x,y,z;cin>>x>>y>>z;
        fir.push_back((edge){x,y,z});
    }
    sort(fir.begin(),fir.end());
    a[0]=get_mst(fir);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        MST now;
        for(int j=1;j<=n-k;j++){
            int z;cin>>z;
            now.push_back((edge){n-k+i,j,z});
        }sort(now.begin(),now.end());
        now=merge_sort(now,a[0]);
        a[1<<(i-1)]=get_mst(now);
    }
    for(int S=1;S<(1<<k);S++){
        int p=(S&-S);
        if(p==S) continue;
        MST now=merge_sort(a[S^p],a[p]);
        a[S]=get_mst(now);
    }
    long long ans=1e18;
    for(int S=0;S<(1<<k);S++){
        long long now=0;
        for(int i=0;i<k;i++){
            if((S>>i)&1) now+=c[i+1];
        }
        for(auto u:a[S]) now+=u.val;
        ans=min(ans,now);
    }
    cout<<ans<<'\n';
}
/*
最后一次 CSPS，AK 了？人生第一次啊
CCF 别卡我常求你了

为什么在高二却输了呢。

lfxxx 24+10+5
*/