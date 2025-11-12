#include<bits/stdc++.h>
using namespace std;
int h,l;
int n,m,mf,x,s=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>mf;
    for(int i=2;i<=n*m;i++){
        cin>>x;
        if(x>mf)s++;
    }
    l=(s-1)/n+1;
    s=(s-1)%n+1;
    if(l%2==0){
        h=n-s+1;
    }
    else h=s;
    cout<<l<<" "<<h;
    return 0;
}
