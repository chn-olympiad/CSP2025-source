#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[m+1],b[m+1],c[m+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int mp[n+1][n+1];
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++){
        mp[a[i]][b[i]]=c[i];
        mp[b[i]][a[i]]=c[i];
    }
    int mo;
    bool f[n],fl=false;
    memset(f,false,sizeof(f));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fl=true;
            for(int 0;l<n;l++){
                if(f[i]==false){
                    fl=false;
                }
            }
            if(fl){
                cout<<mo;
                return 0;
            }
            if(mp[i][j]!=0){
                f[i]=true;
                f[j]=true;
            }
        }
    }
    return 0;
}
