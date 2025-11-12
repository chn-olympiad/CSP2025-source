#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s=1,fx,fy;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])s++;
    }
    if(s%n!=0)fy=s/n+1;
    else fy=s/n;
    cout<<fy<<" ";
    fx=s%n;
    if(fy%2==1){
        if(fx==0)cout<<n;
        else cout<<fx;
    }
    else{
        if(fx==0)cout<<1;
        else cout<<n-fx+1;
    }
    return 0;
}
