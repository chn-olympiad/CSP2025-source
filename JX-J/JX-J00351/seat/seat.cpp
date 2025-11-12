#include<bits/stdc++.h>
using namespace std;
int a,n,m,a1[100],t,k=1,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>t;
    for(int i=1;i<n*m;i++){
        cin>>a;
        if(a>t) k++;
    }
    c=(k-1)/n+1;
    if(c%2!=0) r=k/m+1;
    else  r=n-k/m+1;
    cout<<c<<" "<<r;
    return 0;
}
