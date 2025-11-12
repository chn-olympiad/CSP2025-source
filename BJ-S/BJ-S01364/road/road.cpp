#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e18;
long long minn[20005],d[20005],p[20005],f[20005];
long long b[15][20005],c[15],e[15];
void dfs(int x){
    if(x>k){
        long long sum=0,cnt=n;
        for(int i=1;i<=n;i++){
            d[i]=minn[i];
            f[i]=p[i];
        }
        for(int i=1;i<=k;i++){
            if(c[i]==1){
                cnt++;
                sum+=e[i];
                for(int j=1;j<=n;j++){
                    if(b[i][j]<=d[cnt]){
                        d[cnt]=b[i][j];
                        f[cnt]=j;
                    }
                    if(b[i][j]<=d[j]){
                        d[j]=b[i][j];
                        f[j]=cnt;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(f[f[i]]==i){
                sum-=d[i];
                break;
            }
        }
        for(int i=1;i<=cnt;i++){
            sum+=d[i];
        }
        ans=min(ans,sum);
        return;
    }
    c[x]=0;
    dfs(x+1);
    c[x]=1;
    dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        minn[i]=1e9;
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(z<=minn[x]){
            minn[x]=z;
            p[x]=y;
        }
        if(z<=minn[y]){
            minn[y]=z;
            p[y]=x;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>e[i];
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}