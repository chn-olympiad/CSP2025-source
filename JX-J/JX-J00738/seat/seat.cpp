#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[120];
int s[15][15];
int cnt=1;
void qsort(int z,int y){
    int l=z,r=y;
    if(l>=r) return ;
    int mid=(l+r)/2;
    while(l!=r){
    if(a[l]<a[mid])l++;
    if(a[r]>a[mid])r--;
    int x=a[l];
    a[l]=a[r];
    a[r]=x;
    }
    qsort(1,mid);
    qsort(mid+1,y);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int b=m*n;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    if(a[1]==1){
        if(m%2==0)cout<<m<<" "<<"1";
        else cout<<m<<" "<<n;
    }
    qsort(1,b);

    return 0;
}
