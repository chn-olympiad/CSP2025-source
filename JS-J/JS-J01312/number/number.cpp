#include<bits/stdc++.h>
using namespace std;
int rp[37],ak;
string csp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> csp;
    ak = csp.size();
    for(int j = 0;j < ak;j++){
        if(csp[j] >= '0' && csp[j] <= '9') rp[csp[j]-'0']++;
    }
    for(int oler = 9;oler >= 0;oler--)
        for(int j = 1;j <= rp[oler];j++) cout << oler;
    return 0;
}
