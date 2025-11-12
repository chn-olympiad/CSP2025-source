#include<bits/stdc++.h>
using namespace std;
string s,ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)if(isdigit(s[i]))ans+=s[i];
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
