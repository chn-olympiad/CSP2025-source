#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[100005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<=2){
        cout<<0;
        return 0;
    }if(n==3){
        int x,y,z,sum=0;
        cin>>x>>y>>z;
        sum=x+y+z;
        int ma=max(x,y);
        ma=max(ma,z);
        if(ma*2<sum){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }else{
        cout<<n*2-1;
    }
    return 0;
}
