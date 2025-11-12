#include<bits/stdc++.h>
using namespace std;
int n,a,i,m=0,t=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int m1=n;
    while(m1){
        cin>>a;
        i+=a;
        m=max(m,a);
        m1--;
    }if(n==3){
        if(i>2*m) cout<<1;
        else cout<<0;
        return 0;
    }else if(m==1){
        m1=n;
        while(m1>=3){
            t+=n-m1+1;
            m1--;
        }cout<<t;
        return 0;
    }
    return 0;
}
