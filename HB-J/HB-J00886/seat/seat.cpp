#include<bits/stdc++.h>
using namespace std;
int n,m,a[1919810],b[1919810];
bool cmp(int a,int b){
    return a>b;
}
void cr(int i,int n){
    int c,r;
    if(i/n==0 || i==n) c=1;
    else c=i/n+1;
    if(c%2==0){
        if(i%n==0) r=1;
        else r=n+1-i%n;
    }
    else{
        if(i%n==0) r=n;
        else r=i%n;
    }cout<<c<<' '<<r;
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[i]=a[i];
    }stable_sort(b+1,b+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(b[i]==a[1]){
            cr(i,n);
            return 0;
        }
    }
}
