#include "bits/stdc++.h"
using namespace std;

string s,nw;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            nw+=s[i];
        }
    }
    stable_sort(nw.begin(),nw.end());
    reverse(nw.begin(),nw.end());
    cout<<nw;
    return 0;
}
