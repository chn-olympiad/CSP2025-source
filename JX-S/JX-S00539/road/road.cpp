#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int nn=1e4+5,mm=1e6+5,vv=1e5+5+1e4+5,mk=1e6+5+1e5;
int n,m,k,a[12][nn],c[12],t[vv],b[12][nn],ls[vv],to;
int f[vv],tot;
int vl[vv];
ll ans=1e18;
struct node{
    int u,v,w,vl;
}e[mm],num[nn],vk[mk];

vector<pii>g[vv],r[vv];
int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
bool tmp(node& pa,node& pb){
    return pa.w<pb.w;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    if(k==0 || (k==5 && n<=1e3 && m<=1e5)){
        for(int i=1;i<=m;i++){
            cin>>e[i].u>>e[i].v>>e[i].w;
        }
        //for(int i=1;i<=2*n;i++)f[i]=i;
        for(int i=1;i<=k;i++){
            cin>>c[i];
            for(int j=1;j<=n;j++)cin>>a[i][j];
        }
        for(int ks=0;ks<(1<<k);ks++){
            for(int i=1;i<=n+k+5;i++)f[i]=i;
            to=m;
            for(int i=1;i<=m;i++){
                vk[i].u=e[i].u;
                vk[i].v=e[i].v;
                vk[i].w=e[i].w;
            }
            ll num=0;
            for(int i=0;i<k;i++){
                if((ks&(1<<i))){
                    num+=c[i+1];
                    for(int j=1;j<=n;j++){
                        vk[++to].u=i+n+1;
                        vk[to].v=j;
                        vk[to].w=a[i+1][j];
                    }
                }
            }
            sort(vk+1,vk+to+1,tmp);
            for(int i=1;i<=to;i++){
                int p=find(vk[i].u),q=find(vk[i].v);
                if(p!=q){
                    f[p]=q;
                    num+=vk[i].w;
                }
            }
            ans=min(ans,num);
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=n;++i)f[i]=i;
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j)cin>>a[i][j];
    }
    sort(e+1,e+m+1,tmp);
    for(int i=1;i<=m;++i){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int p=find(u),q=find(v);
        if(p!=q){
            f[p]=q;
            num[++tot].u=u,num[tot].v=v,num[tot].w=w;
        }
    }
    for(int i=1;i<=tot;++i)ls[++to]=num[i].w;
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j)ls[++to]=a[i][j];
    }
    sort(ls+1,ls+to+1);
    int len=unique(ls+1,ls+to+1)-ls-1;
    for(int i=1;i<=tot;++i){
        num[i].vl=lower_bound(ls+1,ls+len+1,num[i].w)-ls;
        vl[num[i].vl]=num[i].w;
        r[num[i].vl].push_back({num[i].u,num[i].v});
    }
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            b[i][j]=lower_bound(ls+1,ls+len+1,a[i][j])-ls;
            vl[b[i][j]]=a[i][j];
        }
    }
    for(int ks=0;ks<(1<<k);++ks){
        for(int i=1;i<=len;++i){
            if(g[i].size()!=0)g[i].clear();
            for(auto [u,v]:r[i]){
                g[i].push_back({u,v});
            }
        }
        ll num=0;
        for(int i=1;i<=n+k;++i)f[i]=i;
        for(int i=0;i<k;++i){
            if((ks&(1<<i))){
                num+=c[i+1];
                for(int j=1;j<=n;++j){
                    g[b[i+1][j]].push_back({i+1+n,j});
                }
            }
        }
        //if(ks==1)cout<<num<<'\n';
        for(int i=1;i<=len;++i){
            for(auto [u,v]:g[i]){
                int p=find(u),q=find(v);
                if(p!=q){
                    //if(ks==1){
                    //    cout<<u<<" "<<v<<'\n';
                    //}
                    f[p]=q;
                    num+=vl[i];
                }
            }
        }
        //if(num==12){
          //  cout<<ks<<'\n';
        //}
        ans=min(ans,num);
    }
    cout<<ans;
    return 0;
}
