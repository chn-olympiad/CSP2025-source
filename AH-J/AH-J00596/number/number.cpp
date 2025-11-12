#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans+=s[i];
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
