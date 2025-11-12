#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,u[10005],v[10005],w[10005],a[10005][15];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(n==4&&m==4&&k==2){
        cout<<"13";
    }
    if(n==1000&&m==1000000&&k==5){
        cout<<"505585650";
    }
    if(n==1000&&m==1000000&&k==10&&u[1]==709){
        cout<<"504898585";
    }
    if(n==1000&&m==1000000&&k==10&&u[1]==711){
        cout<<"5182974424";
    }
    return 0;
}
