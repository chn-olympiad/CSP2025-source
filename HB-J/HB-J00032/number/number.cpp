#include <bits/stdc++.h>
using namespace std;
string s;
int n[15];
int main(){
    cin>>s;
    if(s.size()==1){cout<<s<<'\n';return 0;}
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            //n[s[i]]++;
            //cout<<(int)s[i];
            n[(int)s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(n[i]!=0){
            for(int j=0;j<n[i];j++){
                cout<<i;
            }
        }
    }
    cout<<'\n';
    return 0;
}
