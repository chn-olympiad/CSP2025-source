#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k,h=0;
    if(m==n-1){
        for(int i=1;i<=m;i++){
            int x,y,z;cin>>x>>y>>z;
            h+=z;
        }
        cout<<h;
    }
    else{
        cout<<0;
    }
    return 0;
}