#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int from,to,w;
}e[15451419];
int fa[114511];
int cnt=0;
int n,m,k;
int ff(int x){
    if(fa[x]==x){
        return x;
    }return fa[x]=ff(fa[x]);
}bool cmp(edge a,edge b){
    return a.w<b.w;
}
void add(int u,int v,int w){
    e[cnt].from=u;
    e[cnt].to=v;
    e[cnt].w=w;
    cnt++;
}
int kru(int p){
    int res=0,sum=0;
    for(int i=0;i<cnt;i++){
        if(res==n-1+p){
            return sum;
        }else{
            if(ff(e[i].to)!=ff(e[i].from)){
                res++;
                sum+=e[i].w;
                fa[ff(e[i].to)]=fa[e[i].from];
            }
        }
    }
    return sum;
}
signed main(){
    freopen("road.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);

    }vector<int>v[15];
    int p[114]={0};
    for(int i=1;i<=k;i++){
        cin>>p[i];
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    int ans=1e18;
    for(int i=0;i<(1<<k);i++){
        for(int j=1;j<=n*2;j++){
            fa[j]=j;
        }
        cnt=m-1;
        int c2=0;
    int sum=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){

                c2++;
                sum+=p[j+1];
                for(int kk=1;kk<=n;kk++){

                    add(n+j+1,kk,v[j+1][kk-1]);
                }
            }
        } sort(e,e+cnt,cmp);
        ans=min(ans,kru(c2)+sum);
    }cout<<ans<<endl;
}
