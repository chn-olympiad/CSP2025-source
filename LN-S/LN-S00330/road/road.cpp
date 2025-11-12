#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    int u[1000001],v[1000001],w[100001];
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int c[100001],a[10001][100001];
    for(int j=1;j<=k;j++){
      cin>>c[j];
      for(int i=1;i<=n;i++){
        cin>>a[j][i];
      }
    }
    int maxx=0;
    for(int i=1;i<=m;i++){
        if(maxx<w[i])
            maxx=w[i];

    }
    int cnt=0;

    for(int i=1;i<=m;i++){
        if(w[i]!=maxx)
            cnt+=w[i];
    } maxx=0;

    for(int i=1;i<=k;i++){
        if(u[i]<cnt){int comd=0;
            for(int j=1;j<=m;j++){
                    if(maxx<a[i][j])
                            maxx=a[i][j];
            }
            for(int j=1;j<=m;j++){
                if(a[i][j]!=maxx){
                    comd+=a[i][j];
                }
            }
            if(comd<cnt)
                cnt=comd;
}
    }
    cout<<cnt;
}
