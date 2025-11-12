#include<bits/stdc++.h>
using namespace std;
string num;
char c;
int main(){
#ifndef ASTRALFLARE_CE
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
#endif
    while(cin>>c)if('0'<=c&&c<='9')num+=c;
    sort(num.rbegin(),num.rend());
    cout<<num;
}

// Make AstralFlare Great Again!
// unsigned long long rp=0; --rp;