#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
struct road{
    int u,v,w;
};
int n,m,k;
vector<road> r;
vector<road> l;
int c[15],a[15][N],idx;
bool cmp(road x,road y){
    return x.w<y.w;
}
int f[N+20];
int fnd(int x){
    if(f[x]==x){
        return f[x];
    }
    f[x]=fnd(f[x]);
    return f[x];
}
void meg(int x,int y){
    f[fnd(y)]=fnd(x);
}
int work(){
    sort(l.begin(),l.end(),cmp);
    int res=0;
    for(int i=1;i<=idx;i++){
        f[i]=i;
    }
    int cnt=0;
    for(int i=0;i<l.size();i++){
        if(fnd(l[i].u)!=fnd(l[i].v)){
            meg(l[i].u,l[i].v);
            res+=l[i].w;
            cnt++;
        }
    }
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        r.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ans=6e18;
    for(int q=0;q<(1<<k);q++){
        l=r;
        int p=q;
        int cnt=0,res=0;
        idx=n;
        while(p){
            cnt++;
            if(p&1){
                idx++;
                res+=c[cnt];
                for(int j=1;j<=n;j++){
                    l.push_back({idx,j,a[cnt][j]});
                }
            }
            p>>=1;
        }
        int t=work()+res;
        ans=min(ans,t);
    }
    cout<<ans;
    return 0;
}
