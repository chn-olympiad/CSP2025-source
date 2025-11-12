#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,z,h;
int k[N][4];
int a=0,b=0,c=0,ans;
void fz(int x){
     if(a<=n/2){
        a+=;
        n--;
        h=h+k[x][j];
        ans=ans+k[x][1];
     }
     if(b<=n/2){
        b+=;
        n--;
        h=h+k[x][j];
        ans=ans+k[x][2];
     }
     if(c<=n/2){
        c+=;
        n--;
        h=h+k[x][j];
        ans=ans+k[x][3];
     }
     if(n==0){
        cout<<ans;
    }
}
int main(){
    cin>>t;
    cin>>n;
    z=n;
    for(int i=1;i<=n;i++){
       for(int j=1;j<=3;j++){
           cin>>k[i][j];
       }
       fz(i);
       cout<<endl;
    }

    return 0;
}
