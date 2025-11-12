#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string ans;
    for(int i=0;i<(int)s.size();i++)  if(isdigit(s[i]))  ans+=s[i];
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
