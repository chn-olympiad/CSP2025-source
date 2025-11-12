#include <bits/stdc++.h>
using namespace std;
int n,m,k,u1[1001],v1[1001],w1[1001],f[1001],sum,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u1[i]=u;
            v1[i]=v;
            w1[i]=w;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i!=j){
                if(w1[i]<w1[j]){
                    swap(w1[i],w1[j]);
                    swap(v1[i],v1[j]);
                    swap(u1[i],u1[j]);
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
            if(ans==n){
                cout<<sum;
                return 0;
            }
            int j=0;
        if(f[u1[i]]==0){
            f[u1[i]]=1;
            ans++;
            j=1;
        }
        if(f[v1[i]]==0){
            f[v1[i]]=1;
            ans++;
            j=1;
        }
        if(j==1){
            sum+=w1[i];
        }
    }
    return 0;
}
