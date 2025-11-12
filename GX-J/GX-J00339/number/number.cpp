#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    char b[9];
    string a;
    cin>>a;

    for(int i=0;i<a.length();i++){
        for(int j=0;j<=9;j++){
            if(a[i]-48 == j){
                b[j]++;
            }
        }
    }

    for(int i=9;i>=0;i--){
        for(int j=0;j<b[i];j++){
            cout<<i;
        }
    }
    return 0;
}
