#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,t,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>t;
    for(int i=2;i<=n*m;i++){
        int p;
        cin>>p;
        if(p>t)k++;
    }
    c+=k/(2*n)*2;
    k%=2*n;
    c++;
    if(k<=n){
        r+=k;
    }else{
        c++;
        k-=n;
        r+=n-k+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
