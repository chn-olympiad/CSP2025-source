#include<bits/stdc++.h>
using namespace std;
string s,x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            x+=s[i];
        }
    }
    sort(x.begin(),x.end());
    reverse(x.begin(),x.end());
    cout<<x<<'\n';
    return 0;
}