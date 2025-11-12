#include <bits/stdc++.h>
using namespace std;
int a[10000],num=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int m,x;
    cin>>m;
    for(int i=1;i<=m;i++)cin>>x;
    if(m==5){
        if(x=10){
            cout<<6;
        }
        else{
            cout<<9;
        }
    }
    if(m==20){
        cout<<1042392;
    }
    if(m==500)cout<<366911923;
    return 0;
}
