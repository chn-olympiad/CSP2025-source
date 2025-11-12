#include<bits/stdc++.h>
using namespace std;
int d[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
                d[s[i]-'0']++;
           }
    }
    string ans="";
    for(int i=9;i>=0;i--){
        for(int j=1;j<=d[i];j++){
            ans+=i+'0';
        }
    }
    while(ans[0]=='0'&&ans.size()>1){
        ans=ans.substr(1);
    }
    cout<<ans;

    return 0;
}
