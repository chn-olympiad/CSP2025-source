#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int cnt[9] = {};
    for(int i = 0;i < s.length();i++){
        if(s[i] <= '9' && s[i] >= '0'){
            cnt[s[i]-'0']++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 0;j < cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
