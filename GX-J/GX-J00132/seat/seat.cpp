#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,w,e,y,h;
    cin>>m>>n;
    int d=m*n;
    int s[d];
    v=s[1];
    for(int i=0,i<d,i++){
        cin>>s[i];
    }
    for(int l=0,l<d,l++){
        for(int i=0,i<d,i++){
            if(s[i]<=s[i+1]){
                w=s[i];
                e=s[i+1];
                s[i+1]=w;
                s[i]=e;
            }
        }
    }
    for(int i=0,i<d,i++){
        if(v==s[i]){
            y=i;
        }
    }
    c=y/m;
    if(c/2==0){
        r=y%m;
    }
    if(c/2==1){
        h=y%m;
        r=m-h;
    }
    cout<<c<<r;
    return 0;
}
