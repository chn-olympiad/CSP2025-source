#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int h[100]={};
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>h[i];
        }
    }
    cout<<h[1]+h[0];
    return 0;
}
