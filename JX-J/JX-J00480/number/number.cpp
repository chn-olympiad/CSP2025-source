#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int> mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.osut","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            int t=s[i]-'0';
            mp[t]++;
        }
    }
    for(int i=9;i>=0;i--){
        //cout<<mp[i]<<" ";
        if(mp[i]){
            for(int j=1;j<=mp[i];j++){
                cout<<i;
            }
        }
    }
        
    return 0;
}