#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int a[n*m],p;
    for(int i=0;i<n*m;i++)cin>>a[i];
    p=a[0];
    sort(a,a+n*m);
    reverse(a,a+n*m);
    int k;
    for(int i=0;i<n*m;i++){
        if(a[i]==p){
            k=i+1;break;
        }
    }
    int r=k/(2*n);r*=2;
    k%=(2*n);
    if(k==0){
        cout<<r<<' '<<1;
    }
    else if(k<=n){
        cout<<r+1<<' '<<k;
    }
    else{
        k-=n;
        cout<<r+2<<' '<<n-k+1;
    }
    return 0;
}
