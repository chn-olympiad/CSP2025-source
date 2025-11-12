#include<bits/stdc++.h>
using namespace std;
map<char,long long> m;
string s,ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            m[s[i]]++;
        }
    }
    for(auto it=m.rbegin();it!=m.rend();it++){
        while(it->second--){
            ans+=it->first;
        }
    }
    cout<<ans;
    return 0;
}
