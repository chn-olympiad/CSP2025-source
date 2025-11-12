#include<bits/stdc++.h>
using namespace std;

string s;
int ans[1000010],t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[t]=int(s[i]-'0');
            t++;
        }
    }

    sort(ans,ans+t);
    for(int i=t-1;i>=0;i--){
        cout<<ans[i];
    }

    return 0;
}