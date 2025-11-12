#include<bits/stdc++.h>
using namespace std;
int u[10001],v[10001],w[10001],c[10001],i,n,m,j,k,a[10001][10001],mini1=2e9,mini2=2e9,mina1=2e9,mina2=2e9,minj=2e9,minjz=10001;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    for(j=1;j<=k;j++){
        cin>>c[j];
        for(int x=1;x<=n;x++)cin>>a[j][n];
    }
    for(i=1;i<=m;i++){
        if(w[i] < mini1) mini1=w[i];
        else if(w[i] < mini2 && mini1<mini2) mini2=w[i];
    }
    for(j=1;j<=k;j++){
        if(c[j] < minj){
            minj=c[j];
            minjz=j;
        }
    }
    for(int x=1;x<=n;x++){
        if(a[minjz][x] < mina1) mina1=a[minjz][x];
        else if(a[minjz][x] < mina2 && mina1 < mina2) mina2=a[minjz][x];
    }
    cout<<mini1+mini2+mina1+mina2+minj;
    cout<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
