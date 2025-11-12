#include<bits/stdc++.h>
using namespace std;
int dx(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long gs[m*n]={};
    for(long long a=0;a<m*n;a++){
        cin>>gs[m*n];
    }
    int R=gs[0];
    sort(gs,gs+(m*n),dx);
    int cj;
    for(long long a=0;a<m*n;a++){
        if(gs[a]==R){
           cj=a+1;
           break;
        }
    }
    cout<<cj/m<<" ";
    if((cj/m)%2==0 && cj%m!=0){
        cout<<n-(cj%m)
    }
    else if((cj/m)%2==0 && cj%m==0){
        cout<<"1";
    }
    else if((cj/m)%2!=0 && cj%m!=0){
        cout<<cj%m;
    }
    else if((cj/m)%2!=0 && cj%m==0)
        cout<<n;
    return 0;
}
