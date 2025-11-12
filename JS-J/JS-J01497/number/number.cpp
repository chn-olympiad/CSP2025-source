#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main(){
    freopen("number.in","r",stdin);freopen("number.out","w",stdout);
    string s;cin >> s;
    for(auto i:s)
        if(isdigit(i)) v.push_back(i);
    sort(v.begin(),v.end());reverse(v.begin(),v.end());
    for(auto i:v) printf("%c",i);
    return 0;
}
