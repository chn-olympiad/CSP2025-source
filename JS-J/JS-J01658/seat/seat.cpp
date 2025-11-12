#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],R,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)R=a[i];
    }sort(a+1,a+1+n*m);
    int l=1,r=n*m;
    while(l<r){
        int mid=(l+r)>>1;
        if(a[mid]==R){
            l=mid;
            break;
        }if(a[mid]>R)r=mid-1;
        else l=mid+1;
    }d=n*m-l+1;
    cout<<(d-1)/n+1<<" ";
    if(((d-1)/n+1)%2)cout<<(d-1)%n+1;
    else cout<<n-(d-1)%n;
}
