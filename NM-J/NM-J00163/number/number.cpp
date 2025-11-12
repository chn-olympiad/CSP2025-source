#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    int s = 10000;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    b=a%10;
    c=(a-b)/10;
    d=a/100;
    if(a<10){
        cout<<a;
    }
    if(a>10){
        cout<<b*10+c;

    }
    return 0;
}
