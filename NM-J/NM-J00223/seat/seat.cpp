#include <bits/stdc++.h>
using namespace std;
int m=0,n=0,a=0,b=0,gs=0,bj=0,o=0,k=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>b;
    for(int i=2;i<=m*n;i++){
        cin>>a;
        if(a>b){
            gs+=1;
        }
    }
    o=gs/n;

    if(o%2==0){
        bj=1;
        k=gs%n+1;
    }
    else{
        k=gs%n;
    }
    if(k>n){
        k=k-n;
    }
    if(bj==1){
        cout<<o+1<<" "<<k;
    }
    else{
        cout<<o+1<<" "<<n-k;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
