#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,l,r,p,mid;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            p=a[i];
        }
    }
    sort(a+1,a+n*m+1);
    l=1,r=n*m;
    mid=(l+r)/2;
    while(a[mid]!=p){
        if(a[mid]>p){
            r=mid-1;
        }
        if(a[mid]<p){
            l=mid+1;
        }
        mid=(l+r)/2;
    }
    int x=m-ceil(mid*1.0/n)+1,y=mid%n;
    cout<<x<<" ";
    if(x%2!=0){
        if(y==0){
            y=n;
        }
        cout<<n+1-y;
    }else{
        if(y==0){
            y=n;
        }
        cout<<y;
    }
    return 0;
}
