#include<bits/stdc++.h>
using namespace std;
int s[15][15],ai[105],m,n,r=1,c=1,a0,a0_;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>ai[i];
    }
    a0=ai[1];
    sort(ai+1,ai+n*m+1);
    for(int i=1;i<=m*n;i++){
        if(ai[i]==a0)a0_=i;
    }
    a0_=m*n-a0_+1;
    a0_--;
    while(a0_>=2*n){
        a0_-=2*n;
        c+=2;
    }
    if(a0_>0){
        if(a0_<n){
            r+=a0_;
        }
        else{
            c++;
            a0_-=n;
            r=n-a0_;
        }
    }
    cout<<c<<' '<<r;
}
