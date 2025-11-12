#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],c,r,a1,s;
bool cmp(int a,int b){
    if(a>b){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            a1=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        //cout<<a[i]<<" ";
        if(a[i]==a1){
            s=i;
        }
    }
    if(n==1){
        c=s;
        r=1;
    }
    else if(m==1){
        c=1;
        r=s;
    }
    else if(s%n!=0){
        c=s/n+1;
        if(((s/n)+1)%2==0){
            r=n-(s%n)+1;
        }
        else{
            r=s%n;
        }
    }
    else if(s%n==0){
        c=s/n;
        if((s/n)%2==0){
            r=1;
        }
        else{
            r=n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
