#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    for(int i=1;i<=s.size();i++){
        cin>>s[i];
    }
    int a[1001],ans=0;
    for(int i=1;i<=s.size();i++){
        if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'){
            ans++;
            continue;
        }
        else{
            a[i]=s[i];
        }
    }
    for(int i=1;i<=s.size()-ans;i++){
        cout<<a[i];
    }
    return 0;
}
