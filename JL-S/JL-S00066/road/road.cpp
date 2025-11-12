#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int b[10005];
int n,m,k;
int dfdfdf(){
    int tab;
    while(1){
        int manx=-1,ti=0,tj=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;i++){
                if(manx>a[i][j]) manx=a[i][j],ti=i,tj=j;
            }
        }
        tab+=manx;
        b[ti]++,b[tj]++;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(b[i]!=0) sum++;
        }
        if(sum==n) break;
    }
    return tab;

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,w,v;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;++j){
            int w;
            cin>>w;
            if(k==j) continue;
            if(a[i][j]==0&&a[j][i]==0){
                a[i][j]=w+c;
                a[j][i]=w+c;
            }
            else{
                a[i][j]=min(a[i][j],w+c);
                a[j][i]=min(a[j][i],w+c);
            }
        }
    }
    cout<<dfdfdf();
    return 0;
}
