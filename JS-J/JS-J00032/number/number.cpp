#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin>>str;
    vector<char> v;
    for(int i=0;i<str.size();i++){
        if('0'<=str[i]&&str[i]<='9'){
            v.push_back(str[i]);
        }
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}
