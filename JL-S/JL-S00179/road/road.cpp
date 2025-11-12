#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    ll u[m],v[m],w[m],c[k],a[k][n];
    for(int i=1;i<=m;i++){
       cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
       }

    }
    for(int i=1;i<=m-1;i++){
        for(int j=i+1;j<=m;j++){
            if(u[i]==u[j] && v[i]==v[j]){
                ll ppp;
                ppp=min(w[i],w[j]);
                if(ppp==w[i]){
                    w[j]=-1;
                }
                    else{
                        w[i]=-1;
                    }
            }
        }
    }
    ll money=0;
    ll road[k][m];
    for(int i=1;i<=n;i++){
        ll sum=0;
        if(w[i]!=-1){
            sum+=w[i];
            for(int j=1;j<=k;j++){
                ll qqq;
                qqq=c[j]+a[j][u[i]]+a[j][v[i]];
                if(qqq<w[i]){
                    sum-=w[i];
                    sum+=qqq;
                    if(road[j][u[i]]==1){
                        sum-=a[j][u[i]];
                    }
                    if(road[j][v[i]]==1){
                        sum-=a[j][v[i]];
                    }
                    a[j][u[i]]=1;
                    a[j][v[i]]=1;
                }
            }
        }
        money+=sum;
    }
    cout<<money;
    return 0;
}

