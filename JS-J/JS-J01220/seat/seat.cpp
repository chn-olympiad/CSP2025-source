#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005],n,m,s=1,c,r;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        int k=a[1];
        if(a[i]>k) s++;
    }
    if(s%m==0) c=s/m;
    else c=s/m+1;
    if(c%2){
        if(s%m==0) r=m;
        else r=s%m;
    }
    else{
        if(s%n==0) r=1;
        else r=n-(s%n)+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
