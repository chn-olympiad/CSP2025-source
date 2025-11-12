#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    for(int i=9;i>=0;i--){
        for(int j=0;j<s.size();j++){
            if(s[j]==i+48) cout<<i;
        }
    }
    return 0;
}