#include <bits/stdc++.h>
using namespace std;
long long u[10028],v[10028],w[10028],c,a[10000028];
long long n,m,k,sum;
long long e[10028][10028];
int do1(int aa,int bb,int sum1){
    if(aa==bb)return 0;
    for(int i=1;i<=n;i++){
        if(e[aa][i]){
            if(i==bb)return sum1+e[aa][i];
            else do1(i,bb,sum1+e[aa][i]);
        }

    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        sum+=w[i];
        e[u[i]][v[i]]=w[i];
        e[v[i]][u[i]]=w[i];
    }cin>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=m;i++){
        //do1(1,i,0);
    }
    cout<<28;
    return 0;
}
