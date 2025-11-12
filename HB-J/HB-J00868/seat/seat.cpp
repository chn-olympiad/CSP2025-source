#include<bits/stdc++.h>
using namespace std;
int n,m,seat[200],higher=0,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>seat[i];
        if(seat[i]>=seat[1])higher++;
    }
    if(higher%n==0){
        c=higher/n;
        if(c%2==0)r=1;
        else r=n;
    }else{
        c=higher/n+1;
        r=higher%n;
        if(c%2==0){
            r=n-r;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
