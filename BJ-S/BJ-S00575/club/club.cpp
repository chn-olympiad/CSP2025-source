#include<bits/stdc++.h>
#define int long long
using namespace std;
int d[110][110][110],t,n,m,a[100010],b[100010],c[100010],bb,cc;
bool cmp(int xx,int y){
    return xx>y;
}
struct D{
    int u,v;
}x[100010];
bool cmp(D xx,D y){
    int xxx=max(xx.u,xx.v),yy=max(y.u,y.v);
    if(xxx==yy)return xx.u>y.u;
    return xxx>yy;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin>>t;
    while(t--){
        cin>>n;m=n/2;
        bb=cc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            x[i].u=a[i];
            x[i].v=b[i];
            bb+=b[i];
            cc+=c[i];
        }
        int ans=0;
        if(m<100){
            memset(d,0,sizeof(d));
            d[0][0][0]=0;
            for(int i=0;i<=m;i++){
                for(int j=0;j<=m;j++){
                    for(int k=0;k<=m;k++){
                        if(i+j+k>n)continue;
                        if(i>0)d[i][j][k]=max(d[i][j][k],d[i-1][j][k]+a[i+j+k]);
                        if(k>0)d[i][j][k]=max(d[i][j][k],d[i][j][k-1]+c[i+j+k]);
                        if(j>0)d[i][j][k]=max(d[i][j][k],d[i][j-1][k]+b[i+j+k]);
                        if(ans<d[i][j][k]){
                            ans=d[i][j][k];
                        }
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
