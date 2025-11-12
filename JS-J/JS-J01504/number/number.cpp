#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
long long a[12];
char c;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin >> c){
        if('0' <= c && c <= '9')
            ++a[c-'0'];
    }
    c='9';
    for(int i=9;i>=0;--i){
        for(int j=0;j<a[i];++j)
            cout<<c;
        --c;
    }
    cout<<'\n';
    return 0;
}
