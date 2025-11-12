#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int f[MAXN][MAXN];
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)f[i][j]=0x3fffffff;
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        f[a][b]=c;
        f[b][a]=c;
    }
    int c,jj=0;
    while(cin>>c){
        jj++;
        for(int i=1;i<=n;i++){
            cin>>f[c+n][i];
        }
    }
    for(int kk=1;kk<=n+jj;kk++){
        for(int i=1;i<=n+jj;i++){
            for(int j=1;j<=n+jj;j++){
                f[i][j]=min(f[i][kk]+f[kk][j],f[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=f[1][i];
    }
    cout<<ans;
    return 0;
}
