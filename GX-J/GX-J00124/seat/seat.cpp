#include <bits/stdc++.h>
using namespace std;
int s[10003];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c=0,r=0,h=0,p=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
        if(i==1) h=s[i];}
    sort(s,s+n*m+1);
    for(int i=n*m;i>=1;i--)if(s[i]==h)p=n*m-i+1;
    if(p<=n)c=1,r=p;
    else{c=ceil(p*1.0/n);
        if(c%2!=0){
            r=p%n;
        }else{
            r=(n+1)-(p%n);
        }
    }cout<<c<<" "<<r;
    return 0;
}
