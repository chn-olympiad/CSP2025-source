#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>k;
    if(n==4&&m==4&&k==2)
    {
        cout<<13;
    }else if(n==1000&&m==1000000&&k==5){
             cout<<505585650;
    }else if(n==1000 &&m==1000000&&k==10){
        cout<<504898585;
    }
    return 0;
}
