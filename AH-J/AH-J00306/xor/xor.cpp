#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,k0,a[N],g[N][N],f[N][N],cnt,maxn;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n;l++){
            int j=i+l-1;
            if(j>n) continue;
            g[i][j]=a[i];
            for(int k=i+1;k<=j;k++){
                g[i][j]^=a[k];
            }
            if(g[i][j]!=k0){
                g[i][j]=0;
            }else{
                g[i][j]=1;
            }
            //cout<<g[i][j]<<" "<<i<<" "<<j<<"\n";
        }
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n;l++){
            int j=i+l-1;
            if(j>n) continue;
            f[i][j]=g[i][j];
            for(int k=1;k<=j-i+1;k++){
                f[i][j]=max(f[i][j],f[i][j-k]+g[j-k+1][j]);
                f[i][j]=max(f[i][j],g[i][i+k-1]+f[i+k][j]);
                maxn=max(f[i][j],maxn);
            }
        }
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
