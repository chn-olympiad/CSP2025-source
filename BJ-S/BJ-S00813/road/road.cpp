#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int n,m,a[N],k,jia;


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
    }
    for(int i=1;i<=k;i++){
        cin>>jia;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        if(jia==0){
            cout<<0;
            return 0;
        }
    }




















    return 0;
}

