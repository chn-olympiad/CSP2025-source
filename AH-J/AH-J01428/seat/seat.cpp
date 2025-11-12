#include<bits/stdc++.h>
using namespace std;
int n,m,s[200],a,nm,b,h,l,sh[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    a=s[0];
    nm=n*m;
    sort(s,s+nm);
    for(int i=nm;i>=0;i--){
        if(s[i]==a){
           b=nm-i;
           break;
        }
    }
    if(b%n==0){
        l=b/n;
        }else{
            l=b/n+1;
        }
    if(l%2==1){
        if(b%n==0){
            h=b/l;
        }else{
            h=b%n;
        }
    }else{
        if(b%n==0){
            h=n-b/l+1;
        }else{
            h=n-b%n+1;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
