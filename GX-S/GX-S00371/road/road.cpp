/*
CSP-S 2025
Chengsinuo
GX-S00371
T2 road.cpp
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,k;
int gp[10005][10005];

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=0;i<m;i++){
        int a1,a2,v;
        cin>>a1>>a2>>v;
        gp[a1][a2]=gp[a2][a1]=v;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(gp[i][j]==0)gp[i][j]=gp[i][k]+gp[k][j];
                else if(gp[i][k]+gp[k][j]==0)gp[i][j]=gp[i][j];
                else gp[i][j]=min(gp[i][j],gp[i][k]+gp[k][j]);
            }
        }
    }
    ll ans=0;
    if(k==0){
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)ans+=gp[i][j];
    }
    cout<<ans;
    return 0;
}

//EW
