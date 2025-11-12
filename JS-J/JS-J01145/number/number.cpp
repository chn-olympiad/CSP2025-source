#include<bits/stdc++.h>
using namespace std;
bool isdight(char a){
    return a>='0'&&a<='9';
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>number;
    for(size_t i=0;i<s.length();i++){
        if(isdight(s[i])){
            number.push_back(s[i]-'0');
        }
    }
    sort(number.begin(),number.end());
    for(int i=number.size()-1;i>=0;i--){
        cout<<number[i];
    }
    return 0;
}
