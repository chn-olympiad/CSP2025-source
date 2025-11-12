#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int x,y,z,sum=0;
    cin>>x>>y>>z;
    for(int i=1;i<=y;i++){
        cin>>z>>z>>z;
        sum+=z;
    }
    cout<<sum;
    return 0;
}

