#include<bits/stdc++.h>
using namespace std;
int m,n,a[100],x,c,r,b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==x){
            b=i;
        }
    }
    if(b<m){
        r=b;
        c=1;
    }
    if(b>=m&&b<=2*m){
        r=m-(2*m-b);
        c=2;
    }
    cout<<r<<" "<<c;
    return 0;
}
