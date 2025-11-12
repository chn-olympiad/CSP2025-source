#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out"."w".stdout);
    int m,n,a[101],l=0,r=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]&&i!=1){
            l++;
        }
        else if(a[i]<a[1]&&i!=1){
            r++;
        }
    }
    if(l%n==0){
       if((l/n)%2==0){
            cout<<l%n+1<<" "<<2;
        }
        else{
            cout<<l%n+1<<" "<<n;
        }
    }
    else{
        if((l/n)%2!=0){
            cout<<l%n+2<<" "<<l%m-1;
        }
        else{
            cout<<l%n+2<<" "<<l%m+1;
        }
    }
    return 0;
}


