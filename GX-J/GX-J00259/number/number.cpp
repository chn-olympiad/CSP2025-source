#include<bits/stdc++.h>
using namespace std;
bool tmp(short a,short b){return a>b;}
vector<short> ans;
string a;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(auto i:a){
        if(i>='0'&&i<='9') ans.push_back(i-'0');
    }
    sort(ans.begin(),ans.end(),tmp);
    if(ans[0]==0) return cout<<0,0;
    for(auto i:ans){
        cout<<i;
    }
    return 0;
}
