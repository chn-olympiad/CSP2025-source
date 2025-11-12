#include<bits/stdc++.h>
using namespace std;
int cj(int a,int b){
    return a>b;
}
int n,m,opl;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int k=m*n;
    int a[k]={};
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    int r=a[0],l;
    sort(a,a+k,cj);
    for(int i=0;i<=k;i++){
        if(r==a[i]){
            l=i+1;
            break;
        }
    }
    int c=l/n+1;
    int d,zu=k/n;
    if(c%2==0){
        for(int i=0;i<=k;i++){
        if(r==a[i]){
            d=i-zu+2;
            break;
        }
    }
    }else if(c%2!=0){
        for(int i=0;i<=k;i++){
        if(r==a[i]){
            opl=i-2*zu+2;
            d=n-opl;
            break;
        }
    }
    }
    cout<<c<<" "<<d;
    return 0;
}
