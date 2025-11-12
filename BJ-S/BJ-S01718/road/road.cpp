#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5,K=25;
int n,m,k,tot,f[N+K],now,cul[N*K+M],p;
int u,v,w,c[K],a[K][N];
ll ans=1e18,res;
struct node{
    int fr,to,val;
}e[K*N+M],E[K*N+M];
bool cmp(node x,node y){
    return x.val<y.val;
}int find(int x){
    return (f[x]==x?x:f[x]=find(f[x]));
}
void kruscal(){
    sort(e+1,e+1+tot,cmp);
    for(int i=1;i<=n+k;i++) f[i]=i;
    int sum=0;p=0;
    for(int i=1;i<=tot;i++){
        int fx=find(e[i].fr);
        int fy=find(e[i].to);
        if(fx==fy) continue;
        res+=e[i].val;
        sum++;
        f[fx]=fy;
        cul[++p]=i;
        if(sum==now-1) break;
    }
}
void solve1(){
    ans=res;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            e[++tot]={n+i,j,a[i][j]};
        }
        /*cout<<tot<<'\n';
        for(int i=1;i<=tot;i++){
            cout<<e[i].fr<<' '<<e[i].to<<' '<<e[i].val<<'\n';
        }*/
        res=c[i];now++;
        kruscal();
        if(res<ans){
            ans=res;
            for(int j=tot-n+1,k=1;k<=n,j<=tot;j++,k++)
                E[j]={n+i,k,a[i][k]};
        }else{
            now--;
            tot-=n;
            for(int j=1;j<=tot;j++) e[j]=E[j];
        }
    }
    cout<<ans;
}void solve2(){
    for(int i=1;i<=n-1;i++) E[i]=e[cul[i]];
    for(int i=1;i<=n-1;i++) e[i]=E[i];
    tot=n-1;
    ans=res;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            e[++tot]={n+i,j,a[i][j]};
            E[tot]=e[i];
        }
        /*cout<<tot<<'\n';
        for(int i=1;i<=tot;i++){
            cout<<e[i].fr<<' '<<e[i].to<<' '<<e[i].val<<'\n';
        }*/
        res=c[i];now++;
        kruscal();
        if(res<ans){
            ans=res;tot++;
            for(int i=1;i<=tot;i++) E[i]=e[cul[i]];
            for(int i=1;i<=tot;i++) e[i]=E[i];
        }else{
            now--;
            tot-=n;
            for(int j=1;j<=tot;j++) e[j]=E[j];
        }
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[++tot]={u,v,w};
        E[tot]={u,v,w};
    }now=n;
    kruscal();
    if(m<=1e5||k==0) solve1();
    else solve2();
    return 0;
}
