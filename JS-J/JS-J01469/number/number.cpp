//qia
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileopen(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
    fileopen("number");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    string t;
    for(auto c:s)if(isdigit(c))t+=c;
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(t[0]=='0')cout<<0;
    else cout<<t;
    return 0;
}
//oqi

/*
8:29 吔屎吧！！！
8:40 终于打开了文件 （#上4善3若6水4？）
8:55 过大样例
*/
