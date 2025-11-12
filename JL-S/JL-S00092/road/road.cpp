#include<bits/stdc++.h>
using namespace std;
struct edge{
    int stp,u,v;
    bool operator > (const edge num)const{
        return stp>num.stp;
    }
    bool operator < (const edge num)const{
        return stp<num.stp;
    }
};
const int N=1e4+25,M=1e6+1e5;
priority_queue<edge,vector<edge>,greater<edge> > pq,q;
int n,m,k;
int a[N];
edge e[M];
bool cmp(edge a,edge b){
    return a.stp<b.stp;
}
void retnew(){
    for(int i=0;i<=n+15;i++){
        a[i]=i;
    }
    return ;
}
int fid(int x){
    if(a[x]!=x){
        a[x]=fid(a[x]);
    }
    return a[x];
}
bool f[15];
long long solve(int no){
    pq=q;
    long long ans=0;
    int newid=1;
    for(int i=1;i<=m;i++){
        edge now=e[i];
        while(!pq.empty() && now.stp>=pq.top().stp){
            edge now2=pq.top();
            pq.pop();
            int ix=fid(now2.u),iy=fid(now2.v);
            if(now2.u==no || now2.v==no){
                continue;
            }
            if(ix!=iy){
                ans+=now2.stp;
                a[ix]=iy;
            }
        }
        int ix=fid(now.u),iy=fid(now.v);
        if(ix!=iy){
            ans+=now.stp;
            a[ix]=iy;
        }
    }
    while(!pq.empty()){
        edge now2=pq.top();
        pq.pop();
        int ix=fid(now2.u),iy=fid(now2.v);
        if(now2.u==no || now2.v==no){
            continue;
        }
        if(ix!=iy){
            ans+=now2.stp;
            a[ix]=iy;
        }
    }
    return ans;
}
void del(int no){
    while(!pq.empty()){
        pq.pop();
    }
    while(!q.empty()){
        edge now=q.top();
        q.pop();
        if(now.u==no|| now.v==no){
            continue;
        }
        pq.push(now);
    }
    q=pq;
    return ;
}
int c[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,z;
        scanf("%d%d%d",&u,&v,&z);
        e[i]={z,u,v};
    }
    sort(e+1,e+m+1);
    retnew();
    long long mnans=solve(0),add=0;
//    cout<<mnans;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        add+=c[i];
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            q.push({x,i+n,j});
        }
        retnew();
        int t=solve(0)+add;
        if(t<mnans){
            mnans=t;
            f[i]=1;
        }
        else{
            del(i+n);
            add-=c[i];
        }
    }
    for(int i=1;i<=k;i++){
        if(!f[i]){
            continue;
        }
            retnew();
        int t=solve(i+n)+add-c[i];
        if(t<mnans){
            del(i+n);
            mnans=t;
            add-=c[i];
        }
    }
    cout<<mnans<<'\n';
    return 0;
}
