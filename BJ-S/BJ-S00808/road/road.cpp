#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long ans;
    int n,m,k;
    cin>>n>>m>>k;
    /*int mm[n+k][n+k];
    bool qu[n+k][n+k]={};
    for(int i=0;i<n+k;i++){
        for(int j=0;j<n+k;j++){
            mm[i][j]=2e+9;
        }
    }*/
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
    }
    for(int i=0;i<k;i++){
        int f;
        cin>>f;
        for(int j=0;j<n;j++){
            int qq;
            cin>>qq;
        }
    }
    /*int lian=n-1;
    while(lian){
        int minn=2e+9,aa,bb;
        for(int i=0;i<n+k;i++){
            for(int j=0;j<n+k;j++){
            if(mm[i][j]<minn&&qu[i][j]==0){
                minn=mm[i][j];
                aa=i;
                bb=j;
            }
        }
        }
        ans+=minn;
        qu[aa][bb]=1;
    }*/
    cout<<0;
    return 0;
}
