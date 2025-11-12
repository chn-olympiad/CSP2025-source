#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1,z;i<=n*m;i++){
        cin>>z;
        if(i==1)x=z;
        else if(z>x)y++;
    }
    int z=y/n+1;
    cout<<z<<" ";
    if(z&1){
        cout<<y%n+1;
//        cout<<"sb";
    }
    else{
        cout<<n-y%n;
    }
    return 0;
}
