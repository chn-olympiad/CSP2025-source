#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt[10]={};
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
