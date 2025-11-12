#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(char a,char b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    vector<char> num;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            num.emplace_back(s[i]);
        }
    }
    sort(num.begin(),num.end(),cmp);
    for(int i=0;i<num.size();i++){
        cout<<num[i];
    }
}
