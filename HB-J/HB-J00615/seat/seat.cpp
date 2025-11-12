#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,l,ts,z;
    cin>>n>>m;
    l=n*m;
    for(int i=0;i<l;i++){
        cin>>a[i];
    }
    ts=a[0];
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            if(a[i]<a[j]){
                int t;
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<l;i++){
        if(a[i]==ts){
            z=i+1;
            break;
        }
    }
    if(z==1){
        cout<<"1 1";
        return 0;
    }
    if(z==l){
        cout<<m<<" "<<n;
        return 0;
    }
    int x=0,y=0;
    if(z%n==0){
        x=z/n;
    }else{
        x=z/n+1;
    }
    if(z%n==0){
        y=n;
    }else{
        y=z%n;
    }
    if(x%2==0){
        y=n-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
