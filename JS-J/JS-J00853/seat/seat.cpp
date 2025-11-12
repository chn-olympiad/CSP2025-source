#include<bits/stdc++.h>
using namespace std;
int emp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","m",stdout);
    int n=0,m=0,a[105]={};
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int t=a[0],_t=0;
    sort(a,a+n*m,emp);
    for(int i=0;i<n*m;i++){
        if(a[i]==t){
            _t=i+1;
        }
    }
    int ansx=0,ansy=0;
    if(_t%n==0){
        ansy=_t/n;
    }else{
        ansy=_t/n+1;
    }
    _t=_t%n;
    if(_t==0) _t=n;
    if(ansy%2==0){
        ansx=n-_t+1;
    }else{
        ansx=_t;
    }
    cout<<ansy<<' '<<ansx;
    return 0;
}
