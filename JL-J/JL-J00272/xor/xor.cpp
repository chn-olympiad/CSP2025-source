#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100010],b[100010],g=0,xs=0;
int szr(long long x){
    long long y=0,q=0,d=0;
    if(x%2==0)  d=1;
    while(x!=0){
        y=y*10+x%2;
        x=x/2;
    }
    while(y!=0){
        q=q*10+y%10;
        y=y/10;
    }
    if(d==1)    q=q*10;
    return q;
}
int yh(long long x,long long y){
    long long q=0,t=0,d=0,p=0;
    if(x%10+y%10==0)    d=1;
    while(x!=0&&y!=0){
        if(x%10+y%10==1)    q=10*q+1;
        else    q=q*10;
        t++;
        x=x/10;
        y=y/10;
    }
    while(q!=0){
        p=p*10+q%10;
        q=q/10;
    }
    if(d==1)    p=p*10;
    if(x>y) p=p+x*int(pow(10,t));
    else    p=p+y*int(pow(10,t));
    return p;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=szr(a[i]);
    }
    for(int l=0;l<n;l++){
        xs=b[l];
        if(a[l]==k){
            g++;
        }else{
            for(int r=l+1;r<n;r++){
                xs=yh(xs,b[r]);
                if(xs==szr(k)){
                    g++;
                    l=r+1;
                    break;
                }
            }
        }
    }
    cout<<g;
    return 0;
}
