#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll ans=0;
ll r[10000][10000],q[10000],u[10000],c[10000][10000],t[10000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        t[i]=0;
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        r[u][v]=w;
        r[v][u]=w;
        t[u]=t[u]?min(t[u],w):w;
        t[v]=t[v]?min(t[v],w):w;
    }
    for(int i=n+1;i<=n+k;i++){
        cin>>q[i];
        u[i]=0;
        for(int j=1;j<=n;j++){
            ll w;
            cin>>w;
            r[i][j]=w;
        }
    }
    for(int j=n+1;j<=n+k;j++){
        for(int i=1;i<n;i++){
            for(int b=i;b<=n;b++){
                ll w=r[j][i]+r[j][b]+q[j];
                if(w<r[i][b]){
                    r[i][b]=w-q[j];
                        ans=u[j]?ans:ans+q[j];
                        u[j]=1;
                    r[b][i]=r[i][b];
                }
                w-=q[j];
                t[i]=t[i]?min(t[i],w):w;
                t[b]=t[b]?min(t[b],w):w;
            }
        }
    }
    sort(t+1,t+n+1);
    for(int i=1;i<n;i++){
        ans+=t[i];
    }
    cout<<ans<<endl;
    return 0;
}
