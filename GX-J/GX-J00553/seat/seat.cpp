#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int R=a[0];
    for(int i=0;i<n*m;i++){
        int max=i;
        for(int j=0;j<n*m;j++){
            if(a[max]<a[j]){
                a[max]=a[j];
                a[j]=a[i];
            }
        }
    }
    int x=0;
    for(int i=0;i<n*m;i++){
        if(R==a[i]){
            x=i+1;
        }
    }
    int c=(x-1)/n+1;
    int r;
    for(int i=0;i<x;i++){
        if(c%2==0){
            r=n+1-x%n;
        }
        if(c%2!=0){
            if(c==1){
                r=x;
            }
            if(c!=1){
                r=x-n*(c-1);
            }
        }
    }
    cout<<c<<" "<<r;


    return 0;
}
