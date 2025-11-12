#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    string r="";
    cin>>s;
    for(auto c:s) if(c>='0'&&c<='9') r.push_back(c);
    sort(r.rbegin(),r.rend());
    cout<<r<<'\n';
}