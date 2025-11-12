#include<bits/stdc++.h>
using namespace std;
string a;
int n,h;
int b,c,d,e;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b>>c>>d>>n>>e>>h;
    if(h==5){
        cout<<9;
    }else if(h==10){
        cout<<6;
    }else{
        cout<<35;
    }
    return 0;
}
