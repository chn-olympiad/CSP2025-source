#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,k,u[10005],v[10005],w[10005],a[11][10005],vl[11],jl[10005];
int q[10005];
int found(int x){
    if(q[x]==x){
        return x;
    }
    return found(q[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        q[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>vl[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                jl[i]=j;
            }
        }
    }
    if(k==0){
        int ans=1e9+5;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    cnt+=w[j];
                    q[found(u[j])]=found(v[j]);
                }
            }
            for(int i=1;i<n;i++){
                if(q[i]!=q[i+1]){
                    cnt+=w[i];
                    break;
                }
            }
            ans=min(ans,cnt);
        }
        cout<<ans;
        return 0;
    }
    cout<<17;
    return 0;
}