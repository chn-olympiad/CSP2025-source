#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,ans;
struct node{
    int fr,to,x;
    bool operator<(const node y)const{
        return x<y.x;
    }
}v[100005];
int fa[100005];
int f(int a){
    if(fa[a]==a) return a;
    return fa[a]=f(fa[a]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[++cnt]={a,b,c};
    }
    for(int i=1;i<=k;i++){
        int t;
        cin>>t;
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            v[++cnt]={n+i,j,a};
        }
    }
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    for(int i=1;i<=cnt;i++){
        int f1=f(v[i].fr),f2=f(v[i].to);
        if(f1!=f2) ans+=v[i].x,fa[v[i].fr]=v[i].to;
    }
    cout<<ans;
    return 0;
}
