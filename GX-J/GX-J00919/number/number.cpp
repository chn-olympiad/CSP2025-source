#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a;
    cin>>a;
    int g,s,x;
    if(a<10){
        cout<<a;
        return 0;
    }
    else{
        g=a%10;
        s=(a-g)/10;
        if(g<s){
            cout<<s<<g;
        }
        else
            cout<<g<<s;
    }
    return 0;
}
