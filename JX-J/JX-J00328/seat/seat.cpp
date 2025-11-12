#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m]={};
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[0],az=0;
    for(int i=0;i<n*m;i++){
        if(s<a[i])az++;
    }
    az++;

    int l,r;
    l=az/n+1;
    r=az%n;
    if(r==0){
        r=n;
        l--;

    }
    if(l%2==0){
        r=n-r+1;
    }
    cout<<l<<" "<<r;
    return 0;
}
