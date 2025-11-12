#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            v.push_back(int(s[i]-'0'));
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
}
