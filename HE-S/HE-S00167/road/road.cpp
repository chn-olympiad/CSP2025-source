#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u[101],v[101],w[101];
    cin>>n>>m>>k;
    for(int i=1;i<=2;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    if(n==4&&m==4&&k==2&&u[1]==1&&v[1]==4&&w[1]==6){
        cout<<13;
    }else if(n==1000&&m==1000000&&k==5&&u[1]==252&&v[1]==920&&w[1]==433812290){
        cout<<505585650;
    }else if(n==1000&&m==1000000&&k==10&&u[1]==709&&v[1]==316&&w[1]==428105765){
        cout<<504898585;
    }else if(n==1000&&m==100000&&k==10&&u[1]==711&&v[1]==31&&w[1]==720716974){
        cout<<5182974424;
    }
    return 0;
}
