#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m,a;
    cin>>n;
    if(n>=10;n<100){
       m=n%10;
       a=n/10;
       if(m>=a){
        cout<<10*m+a;
        return 0;
       } else{
       cout<<10*a+m;
       return 0;
       }
    }else{
        cout<<n;
        return 0;
    }
    return 0;
}
