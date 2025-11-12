#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){cin>>a[i];}
    int q=a[1],rk;
    sort(a+1,a+k+1);
    for(int i=1;i<=k;i++){
        if(a[i]==q){rk=k-i+1;break;}
    }
    int r=rk%(2*n),c=rk/(2*n)*2+1;
    if(r>n){c++,r=2*n-r+1;}
    cout<<c<<' '<<r<<'\n';
    return 0;
}