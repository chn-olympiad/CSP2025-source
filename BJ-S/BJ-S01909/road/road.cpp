#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,f[10005];
ll ans = 0;
struct edge{
    int u,v;
    ll w;
    bool const operater<(edge &r){
        return w<r.w;
    }
};

priority_queue <edge> e;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>> n >> m >> k;
    for(int i=1;i<=m;i++){
        int uf,vf;
        ll wf;
        cin>> uf >>vf >> wf;
        e.push({uf,vf,wf});
        e.push({vf,uf,wf});
    }
    for(int j=1;j<=k;j++){
        ll c;
        cin>> c;
        for(int i=1;i<=n;i++){
            ll wf;
            cin>>wf;
            e.push({i,j,c+wf});
            e.push({j,i,c+wf});
        }
    }
    for(int i=1;i<=n;i++){
        f[i] = i;
    }
    for(auto {uf,vf,wf}:e){
        if(f[vf]!=f[uf]){
           f[vf] = f[uf];
           ans += wf;
        }
        e.pop();
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}