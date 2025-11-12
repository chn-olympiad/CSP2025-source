#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,z,h;
int k[N][4];
int a=0,b=0,c=0;
void fz(int x){
     if(b<=n/2){
        b+=;
        n--;
        h=h+a[x][j];
     }
     if(a<=n/2){
        a+=;
        n--;
        h=h+a[x][j];
     }
     if(c<=n/2){
        c+=;
        n--;
        h=h+a[x][j];
     }

}
int main(){
    cin>>t;
    cin>>n;
    z=n;
    for(int i=1;i<=n;i++){
       for(int j=1;j<=3;j++){
           cin>>k[i][j];
           fz(i);
       }
       cout<<endl;
    }

    return 0;
}
