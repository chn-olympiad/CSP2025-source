#include<bits/stdc++.h>
using namespace std;
string in;
long long ton[10];
int main() {
    //  #1,2:AC
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>> in ;
    for(int i=0;i<in.size();i++){
        if(in[i]>='0'&&in[i]<='9'){
            ton[in[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=ton[i];j++){
            cout<< i ;
        }
    }
    return 0;
}