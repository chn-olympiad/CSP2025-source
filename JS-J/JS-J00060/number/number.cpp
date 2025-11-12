#include<bits/stdc++.h>
using namespace std;
string c;
long long h[100];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out","w",stdout);
    cin >> c;
    for(auto x:c) {
        if('0'<=x&&x<='9') {
            h[x-'0']++;
        }
    }
    bool f=0;
    for(int i=9; i>=1; i--) {
        for(int j=1; j<=h[i]; j++) cout << i,f=1;
    }
    if(f==0 && h[0]>0) {
        cout << 0;
    }else {
        for(int j=1; j<=h[0]; j++) cout << 0;
    }
    return 0;
}
