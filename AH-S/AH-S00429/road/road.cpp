#include<iostream>
#include<cstring>
using namespace std;
long long a[10005][10005];
long long c[15];
bool vis[10005][10005];
long long cl[10005];
long long n,m,k,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(a,1000000005,sizeof(a));
    cin>>n>>m>>k;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        cin>>a[x][y];
    }
    for(int i=1;i<=k;i++){
            cin>>c[i];
        for(int j=1;j<=n;j++){
                long long xb;
                cin>>xb;
                cl[j]=min(cl[j],xb);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=min(a[i][j],cl[i]+cl[j]);
            a[j][i]=min(a[j][i],a[i][j]);
            a[i][j]=min(a[i][j],a[j][i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                 sum+=a[i][j];
        }
    }
    cout<<sum/2;
    return 0;
}
