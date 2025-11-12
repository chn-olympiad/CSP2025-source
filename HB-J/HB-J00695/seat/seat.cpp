#include<bits/stdc++.h>
using namespace std;
int a[100],n,m,r,seat=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    for(int i=1;i<n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=m*n;i++){
        if(r==a[i]){seat=i;break;}
    }
    //cout<<seat<<endl;
    cout<<(seat-1)/n+1<<" ";
    if(((seat-1)/n+1)%2==1){
        if(seat%n!=0)cout<<seat%n;
        else cout<<n;
    }
    else {
        if(seat%n!=0)cout<<n-seat%n+1;
        else cout<<1;
    }
    return 0;
}
