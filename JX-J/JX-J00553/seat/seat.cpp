#include<bits/stdc++.h>
using namespace std;
int b[120];
int main(){
    int n,m,r=0,z=0,l=0,h=0;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int a;
        cin>>a;
        if(i!=1){
            b[a]++;
        }
        else {
            b[a]++;
            r=a;
        }
    }
    for(int i=100;i>=0;i--){
        if(b[i]==1 && i>r)z++;
    }
    l=z/n+1;
    if(l%2==1 && z%n==0)h=1;
    else if(l%2==1)h=z%n+1;
    else if(l%2==0 && z%n==0)h=n;
    else if(l%2==0 )h=n-z%n;
    cout<<l<<" "<<h;


}
