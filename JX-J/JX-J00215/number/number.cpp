//80-100pts
#include<bits/stdc++.h>
using namespace std;
string s,t;
map<int,int>mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            mp[s[i]-'0']++;
        }
    }
    for(pair<int,int>i:mp){
        while(i.second){
            t.push_back(i.first+'0');
            i.second--;
        }
    }
    if(t[t.size()-1]=='0'){
        cout<<0;
        return 0;
    }
    for(int i=t.size()-1;i>=0;i--){
        cout<<t[i];
    }
    return 0;
}