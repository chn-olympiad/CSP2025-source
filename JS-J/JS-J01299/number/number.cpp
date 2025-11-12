#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<char> v;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i]);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
    return 0;
}
