#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100],a1,zw=0,q=0,l,h;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    a1=a[0];
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        q++;
        if(a[i]==a1){
            zw=q;
            break;
        }
    }
    l=ceil(zw*1.0/n);
    h=zw-(l-1)*n;
    if(l%2==1){
        cout<<l<<" "<<h;
    }
    else{
        cout<<l<<" "<<m-h+1;
    }
    return 0;
}
