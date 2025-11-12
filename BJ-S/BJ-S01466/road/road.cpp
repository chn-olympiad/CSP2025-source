#include<bits/stdc++.h>
using namespace std;
int x=1001;
int n,m,k,u[1001],c,v[1001],t[1001],w[1001],ans=0;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++)
            cin>>u[i]>>v[i]>>t[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>w[j];
            if(c+w[j]<=t[j]){
                ans+=c+w[j];
            }
        }
    }
    cout<<ans;
}
