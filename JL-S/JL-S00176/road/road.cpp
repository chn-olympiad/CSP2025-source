#include<bits/stdc++.h>
using namespace std;
int n,m[10025][10025],k,mm;
int u,v,w,sum;
int c[15],a;
int f[10005][10005];
bool cc[15];
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>mm>>k;
    for(int i=1;i<=mm;i++){
        cin>>u>>v>>w;
        m[u][v]=w;
        m[v][u]=w;
        f[u][v]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a;
            m[j][i+n]=a;
            m[i+n][j]=a;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i][j]==0) f[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=2;j<=n+k;j++){
            if(j<=n){
                if(m[i][j]==0 || m[j][i+1]==0){
                    continue;
                }
                if(m[i][j]+m[j][i+1]>f[i][j]){
                    f[i][j]=m[j][i+1]+m[i][j];
                }
            }
            if(f[i]>m[i][j+n]+m[j+n][i+1]+c[j-n]){
                if(cc[i]==false){
                    f[i]=m[i][j]+m[j][i+1]+c[i];
                    cc[i]=true;
                    continue;
                }
                if(cc[i]==true){
                    f[i]=m[i][j]+m[j][i+1];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        sum+=f[i];
    }
    cout<<sum;
    return 0;
}
