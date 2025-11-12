#include <bits/stdc++.h>
using namespace std;
string s[100000];
int sa[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int k=0;
    for(int j=0;j<=1000000;j++){
        for(int i=0;i<10;i++){
           if(s[k] == i){
                sa[k] == s[k];
           }
        }
        k++

    }


    return 0;

}
