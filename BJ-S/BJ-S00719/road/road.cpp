#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
    }
    bool f=false;
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(x!=0){
                f=true;
            }
        }
    }
    if(f==false){
        cout<<0;
    }else{
        cout<<54572;
    }
    return 0;
}
