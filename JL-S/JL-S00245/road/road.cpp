#include<bits/stdc++.h>
using namespace std;
long long a[10100][10100];
long long boo[10100][10100];
long long h[1001000];
bool booh[1001000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(boo,INT_MAX,sizeof(INT_MAX));
    memset(a,INT_MAX,sizeof(INT_MAX));
    long long n,m,k;
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(long long i=1;i<=k;i++){
        long long c;
        cin>>c;
        h[m+i]=c;
        for(long long j=1;j<=n;j++){
             long long w;
            cin>>w;
            a[j][m+i]=w;
            a[m+i][j]=w;
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n+k;j++) {
            boo[i][j]=a[i][j];
            boo[j][i]=a[i][j];
        }
    }
    for(long long i=1;i<=n-1;i++){
        for(long long j=n+k;j>=i+1;j--){
            if(a[i+1][j]!=INT_MAX&&boo[i][j]!=INT_MAX){
                if(a[i+1][j]+boo[i][j]<=a[i][i+1]){
                    if(j>n&&!booh[j]){
                        boo[i][i+1]=a[i+1][j]+boo[i][j]+h[j];
                        boo[i+1][i]=a[i+1][j]+boo[i][j]+h[j];
                        boo[1][i+1]=boo[1][i]+boo[i][i+1]+h[j];
                        boo[i+1][1]=boo[1][i]+boo[i][i+1]+h[j];
                        a[i][i+1]=a[i+1][j]+boo[i][j]+h[j];
                        a[i+1][i]=a[i+1][j]+boo[i][j]+h[j];
                    }
                    else{
                        boo[i][i+1]=a[i+1][j]+boo[i][j];
                        boo[i+1][i]=a[i+1][j]+boo[i][j];
                        boo[1][i+1]=boo[1][i]+boo[i][i+1];
                        boo[i+1][1]=boo[1][i]+boo[i][i+1];
                        a[i][i+1]=a[i+1][j]+boo[i][j];
                        a[i+1][i]=a[i+1][j]+boo[i][j];
                        a[1][i+1]=a[1][i]+a[i][i+1];
                        a[i+1][1]=a[1][i]+a[i][i+1];
                    }
                }
            }

        }
    }
    cout<<boo[1][n]<<endl;
    return 0;
}

