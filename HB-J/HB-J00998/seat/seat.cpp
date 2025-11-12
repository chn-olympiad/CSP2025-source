#include<bits/stdc++.h>
using namespace std;
const int mx=1E7;
int n,m,a[mx],c,r,R,sum=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    for(int i=1;i<=n*m;i++){
        if(a[i]>R){
            sum++;
        }
    }
    r=sum%n;
    c=sum/n+1;
    if(c%2==0){
        r=m-r+1;
    }
    if(c%2!=0){
        r++;
    }
    cout<<c<<" "<<r;
    return 0;
}
