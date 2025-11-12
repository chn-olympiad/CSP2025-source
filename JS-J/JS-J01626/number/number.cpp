#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int cnt[10]={0};
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            cnt[s[i]-'0']++;
        }
    }
    bool f=0;
    for(int i=1;i<=9;i++){
        if(cnt[i]>0){
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++)
            cout<<char('0'+i);
    }
    return 0;
}
