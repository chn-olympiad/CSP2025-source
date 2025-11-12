#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[220000][2];
string t[220000][2];
long long ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
    for(int i=1;i<=q;i++){
        ans=0;
        cin>>t[i][0]>>t[i][1];
        for(int j=1;j<=n;j++){
            for(int k=0;k+s[j][0].size()<=t[i][0].size()&&k+s[j][0].size()<=t[i][1].size();k++){
                if(s[j][0]==t[i][0].substr(k,s[j][0].size())&&s[j][1]==t[i][1].substr(k,s[j][1].size())&&t[i][0].substr(0,k)==t[i][1].substr(0,k)&&t[i][0].substr(k+s[j][0].size(),t[i][0].size()-k+s[j][0].size())==t[i][1].substr(k+s[j][0].size(),t[i][1].size()-k+s[j][0].size())) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
