#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
const int M = 1e6+5;
int n,m,k,cnt,tot;
long long ans;
long long c[15],s[15];
int p[N<<1];
struct edge{
    int u,v;
    long long w;
}e[M<<1];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int found(int x){
    if(p[x]!=x)p[x] = found(p[x]);
    return p[x];
}
int main(){
    freopen("roadt.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>e[m+i*j].w;
            e[m+i*j].u = j;
            e[m+i*j].v = n+i;
        }
    }
    for(int i=1;i<=n+k;i++){
        p[i]=i;
    }
    sort(e+1,e+m+n*k+1,cmp);
    for(int i=1;i<=n;i++){
        int tw = e[i].w;
        int tu = e[i].u;
        int tv = e[i].v;
        if(found(tu)!=found(tv)){
            p[tu] = p[tv];
            ans+=tw;
            //if(tu>n)s[tu]++;
            //if(tv>n)s[tv]++;
        }
    }
    /*long long mn=0;
    for(int i=1;i<=k;i++){
        mn = 1145141919810;
        if(s[i]==1){
            for(int j=m+i*k;j<m+(i+1)*k;j++){
                mn = min(e[j].w,mn);
            }
            ans-=mn;
        }
    }*/
    cout<<ans<<endl;
    return 0;
}
