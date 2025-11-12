#include <bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (auto c:s){
        if (c>='0' && c<='9')++num[c-'0'];
    }
    for (int z=9;z>=0;--z){
        while (num[z]--)cout<<char(z+'0');
    }
    cout<<'\n';
    return 0;
}
