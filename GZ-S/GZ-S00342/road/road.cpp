//GZ-S00342 贵阳市第三实验中学 王钦澄
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000000005],v[1000000005],w[1000000005],c[1000000005],a[1000000005][1000000005];
int city1(int q,int p){
    long long g=20000000000;
    for(int i=1;i<=m;i++){
        if(u[i]==q && v[i]==p){
            g=min(g,w[i]);
        }if(v[i]==q && u[i]==p){
            g=min(g,w[i]);
        }
    }
    return g;
}
int city2(int q,int p){
    long long g=20000000000;
    for(int i=1;i<=m;i++){
        if(u[i]==q){
            if(v[i]==p){
                return w[i];
            }
            g=min(g,w[i]+city2(v[i],p));
        }if(v[i]==q){
            if(u[i]==p){
                return w[i];
            }
            g=min(g,w[i]+city2(u[i],p));
        }
    }
}
int countryside(int q,int p){
    long long g=c[1]+a[1][q]+a[1][p];
    for(int i=2;i<=k;i++){
        g=min(g,c[i]+a[i][q]+a[i][p]);
    }
    return g;
}
int toward(int q,int p){
    int g=countryside(q,p);
    g=min(g,city1(q,p));
    g=min(g,city2(q,p));
    return g;
}
int themin(){
    int g=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            g+=toward(i,j);
        }
    }
    g=g/n;
    return g;
}
int main(){
    freopen("road.in",r,stdin);
    freopen("road.out",w,stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    cout << themin();
    return 0;
}
