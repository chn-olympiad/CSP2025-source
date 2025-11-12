#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[110],b,n,m,c,r;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+n*m-1,cmp);
    for(int i=0;i<n*m;i++){
        if(b==a[i]){
            b=i+1;
            break;
        }
    }
    if(b%n==0){
        c=b/n;
        if(c%2==0){
            r=1;
        }else{
            r=n;
        }
    }else{
        c=b/n+1;
        if(c%2==0){
            r=n-b%n+1;
        }else{
            r=b%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
