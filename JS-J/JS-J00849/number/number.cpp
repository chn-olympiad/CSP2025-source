#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int> mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    for(int i=9;i>=0;i--){
        char ch=i+'0';
        for(int j=1;j<=mp[ch];j++){
            cout<<ch;
        }
    }
    return 0;
}
