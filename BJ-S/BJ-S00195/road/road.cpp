#include <bits/stdc++.h>
using namespace std;
int maxx[10],t,m,n,k,u[100000],sum,v[100000],w[1000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        if(i%2==0) sum+=w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>maxx[i]>>maxx[i+1]>>maxx[i+2]>>maxx[i+3]>>maxx[i+4];
    }
    cout<<sum;
    return 0;
}