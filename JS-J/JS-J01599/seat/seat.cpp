#include<bits/stdc++.h>
using namespace std;
int n,m,f,c,r,v[115];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>v[i];
    f=v[1];
    sort(v+1,v+n*m+1);
    int l=0,r=n*m+1,mid;
    while(l+1<r){
        mid=(l+r)>>1;
        if(f>=v[mid]) l=mid;
        else r=mid; 
    }
    l=n*m-l+1;
    if(l%n) {c=l/n+1; r=(c%2 ? l%n:n-l%n+1);}
    else {c=l/n; r=(c%2 ? n:1);}
    cout<<c<<' '<<r;
}