#include<bits/stdc++.h>
using namespace std;
const int max_n=111111;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>  a;
    for(int i=0;i<s.size();i++){
        if(int(s[i])>=48&&int(s[i])<=57) a.push_back(int(s[i])-48);
    }
    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
