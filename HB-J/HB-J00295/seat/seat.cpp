#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
int n,m,l,h,a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m; int nm=1;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
        if(i==1) continue;
        if(a[i]>a[1]) ++nm;
    }
    // cout<<nm<<" ";
    l=(nm+n-1)/n,h=nm%n;
    // cout<<l<<" "<<h; 
    if(l%2==1){
        if(h==0) h=n;
        else h=nm%n;
    }
    else{
        if(h==0) h=1;
        else h=n-h+1;
    }
    cout<<l<<" "<<h;
    return 0;
}