#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=1e4+50,kmaxm=1e6+10,kl=11;
int n,m,k;
struct edge{
    int u,v,w;
}E[kmaxm];
vector<edge>V;
int c[kl],r[kl][kmaxn];
int f[kmaxn];
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int Sol(int K){//判断选择一个子集的情况的答案
    vector<edge>P;P=V;
    int ans=0;
    for(int i=1;i<=k;i++){
        if(K&(1<<i)){
            ans+=c[i];
            for(int j=1;j<=n;j++){
                edge C;C.u=n+i,C.v=j,C.w=r[i][j];
                P.push_back(C);
            }
        }
    }
    sort(P.begin(),P.end(),cmp);
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(edge i:P){
        if(F(i.u)!=F(i.v)){
            f[F(i.u)]=F(i.v);ans+=i.w;
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>E[i].u>>E[i].v>>E[i].w;
    }
    sort(E+1,E+1+m,cmp);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        if(F(u)!=F(v)){
            f[F(u)]=F(v);
            V.push_back(E[i]);
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>r[i][j];
    }
    int now=0,ans=Sol(now);
    for(int i=1;i<=k;i++){
        int o=Sol(now^(1<<i));
        if(o<ans){
            now^=(1<<i);ans=o;
            for(int j=i-1;j>=1;j--){
                if(now&(1<<j)){
                    int d=now^(1<<j),p=Sol(d);
                    if(p<ans){
                        now=d;ans=p;
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}