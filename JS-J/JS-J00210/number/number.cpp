#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    vector<int>a(10,0);
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0 && s[i]-'0'<10)a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(a[i]--){
            cout<<i;
        }
    }
    return 0;
}