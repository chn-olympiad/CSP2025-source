#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    int a[1000001];
    int jilu,jilu2,paiming;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
        jilu=a[1];
    }
    sort(a+1,a+m*n+1);
    for(int i=m*n/2;;){
        jilu2=m*n;
        if(jilu<a[i]){
            jilu2=i;
            i=i/2;
        }
        if(jilu<a[i]){
            i+=(jilu2-i)/2;
        }
        if(jilu==a[i]){
            paiming=m*n-i;
            break;
        }
    }
    if(paiming%m==0){
        cout<<paiming/m<<" ";
        if((paiming/m)%2==1){
            cout<<m;
        }
        else{
            cout<<"1";
        }
    }
    else{
        cout<<paiming/m+1<<" ";
        if((paiming/m+1)%2==1){
            cout<<paiming%m;
        }
        else{
            cout<<m-paiming%m+1;
        }
    }
    return 0;
}
