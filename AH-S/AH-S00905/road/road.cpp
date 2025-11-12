#include<bits/stdc++.h>
using namespace std;
long long n,m,k,pra[10010],u[1000010],v[1000010],w[1000010],c[100],a[100][10010];
long long myfind(long long x){
    if(pra[x]!=x){
        pra[x]=myfind(pra[x])
    }
    return pra[x];
}
void myuint(long long x,long long y){
    long long rx=myfind(x);
    long long ry=myfind(y);
    if(rx!=ry){
        pra[rx]=ry;

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=n;i++){
        pra[i]=i;
    }
    for(long long i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    return 0;
}
