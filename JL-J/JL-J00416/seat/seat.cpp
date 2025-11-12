#include<bits/stdc++.h>
using namespace std;
int a[1145],n,m,c,r,num,tool,s[1145];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++){
        cin>>s[i];
    }
    tool=s[1];
    sort(s+1,s+n*m+1);
    if(s[1]==tool){
        cout<<m<<' '<<n;
        return 0;
    }
    if(s[1]==tool&&n==2&&m==1){
        cout<<1<<' '<<2;
    }
    else if(s[1]==tool&&n==1&&m==2){
        cout<<2<<' '<<1;
    }
    else if(s[2]==tool&&n==2&&m==1){
        cout<<1<<' '<<1;
    }
    else if(s[2]==tool&&n==1&&m==2){
        cout<<1<<' '<<1;
    }
    if(n==1&&m==1){
        cout<<1<<' '<<1;
        return 0;
    }
    for(int i=n*m;i>=1;i--){
        if(s[i]==tool){
           num=n*m+1-i;
           break;
        }
    }
    if((num/n)%n!=0&&num%n!=0){
        if((num>n&&num<(2*n))||(num>(3*n)&&num<(4*n))||(num>(5*n)&&num<(6*n))||(num>(7*n)&&num<(8*n))||(num>(9*n)&&num<(10*n))){
            c=num/n;
            c++;
            r=n-(num%n);
        }
        else{
            c=num/n+1;
            r=num%n;
        }
    }
    else if(num<n){
        c=1;
        r=num;
    }
    else if(num==n){
        cout<<1<<' '<<n;
        return 0;
    }
    else if(num%n==0){
        if((num/n)%2!=0){
            c=num/n;
            r=n;
        }
        else{
            c=num/n;
            r=1;
        }
    }
    cout<<c<<' '<<r;
    return 0;
}
