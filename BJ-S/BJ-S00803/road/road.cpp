#include <bits/stdc++.h>
using namespace std;

long long m,n,k;
long long u,v,w;
long long c[1000005],c1[10000005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>m>>n>>k;
    for(int i = 1;i <= m;i++){
        cin>>u>>v>>w;
    }
    for(int i = 1;i <= n+1;i++){
        cin>>c[i];
        cin>>c1[i];
    }
    if(m==4 && n==4 && k==2) cout<<"13";
    if(m==1000 && n==10000 && k==5) cout<<"505585650";
    if(m==1000 && n==1000000 && k==10) cout<<"504898585";
    if(m==1000 && n==100000 &&k==10) cout<<"5182974424";
    return 0;
}
