#include<bits/stdc++.h>
using namespace std;
int n,m,b[101],s,p,o,q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    s=b[0];
    for(int i=0;i<n*m;i++){
        if(b[i]>s){
            p++;
        }
    }
    int ser=p+1;
    if(ser%n!=0 && (ser/n+1)%2==1){
        o=ser/n+1;
        q=ser%n;
    }
    else if(ser%n==0 && (ser/n+1)%2==1){
        o=ser/n;
        q=m;
    }
    else if(ser%n!=0 && (ser/n+1)%2==0){
        o=ser/n+1;
        q=m-(ser%n)+1;
    }
    else if(ser%n==0 && (ser/n+1)%2==0){
        o=ser/n;
        q=1;
    }
    cout<<o<<" "<<q;
    return 0;
}
