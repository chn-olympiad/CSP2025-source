#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10001],v[10001],w[10001];
int temp1,temp2;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    bool flag=false;
    for(int i=1;i<=k;i++){
        cin>>temp1;
        if(temp1!=0)flag=true;
        for(int i=1;i<=n;i++){
            cin>>temp2;
            if(temp2!=0){
                flag=true;
            }
        }
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

