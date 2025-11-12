#include<iostream>
using namespace std;
const long long min_0=3e9+5;
long long a[1005][1005];
int main(){
    freopen("road3.in","r",stdin);
    freopen("road3.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    long long u,v,w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=min_0;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        if(w<a[u][v]){
            a[u][v]=w;
            a[v][u]=w;
        }
    }
    for(int i=1;i<=k;i++){
        long long s,t;
        scanf("%lld",&s);
        long long c[1005];
        for(int j=1;j<=n;j++) scanf("%lld",&c[j]);
        for(int l=1;l+1<=n;l++){
            for(int r=l+1;r<=n;r++){
                t=s+c[l]+c[r];
                if(t<a[l][r]){
                    a[l][r]=t;
                    a[r][l]=t;
                }
            }
        }
    }
    long long cnt=0;
    for(int i=1;i+1<=n;i++){
        long long minn=min_0,idx=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]<=minn&&i!=j){
                minn=a[j][i];
                idx=j;
            }
        }
        cnt+=minn;
        a[i][idx]=min_0;
    }
    cout<<cnt;
    return 0;
}
