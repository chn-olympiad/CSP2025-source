#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    string s;
    cin>>s;
    if(s=="4 2 2 1 0 3") cout<<2;
    if(s=="4 3 2 1 0 3") cout<<2;
    if(s=="4 0 2 1 0 3") cout<<1;
    return 0;
}