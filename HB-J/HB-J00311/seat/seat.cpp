#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a>b){
        return true;
    }
    else{
        return false;
    }
}
main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    int m,n,l,c=0,r=0,o,k;
    cin>>n>>m;
    l=n*m;
    int a[l];
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    o=a[0];
    sort(a,a+l,cmp);
    for(int i=0;i<l;i++){
            if(a[i]==o){
                k=i+1;
            }
    }
    c=(k-1)/n+1;
    if(c%2==0){
        r=(k-(c-1)*n)-1;
        r=n-r;
    }
    else{
        r=k-(c-1)*n;
    }
    cout<<c<<" "<<r;
    return 0;
}
