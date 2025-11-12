#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long a[20]={0};
    string s,ans="";
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z') continue;
        else a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        int x=i;
        if(a[i]){
            while(a[i]--){
               ans=ans+char(x+'0');
            }
        }else{
            continue;
        }
    }
    cout<<ans;
    return 0;
}
