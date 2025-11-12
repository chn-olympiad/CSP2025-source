#include<bits/stdc++.h>
using namespace std;
int s[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long a,b,c,d,e,m,n;
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
    cin>>s[i];}
    c=s[0];
    sort(s,s+a*b);
    d=a*b;
    for(int i=0;i<a*b;i++){
        if(s[i]==c){
            e=d-i;
        }
    }
    m=e/a;
    n=e%a;
    if(m%2=='0'){
        cout<<m<<" "<<n;
    }
    else{
        cout<<m<<" "<<b-n;
    }
    return 0;
}
