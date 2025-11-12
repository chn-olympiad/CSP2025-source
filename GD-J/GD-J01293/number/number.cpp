#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],pos;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0') ans[++pos]=s[i]-'0';
    }
    sort(ans+1,ans+pos+1);
    for(int i=pos;i>=1;i--) cout<<ans[i];
    return 0;
}
