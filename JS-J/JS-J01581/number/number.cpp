#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<ll> ans;
bool zf;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') ans.push_back(s[i]-'0');
    sort(ans.begin(),ans.end());
    if(ans[ans.size()-1]==0){
        cout<<0;
        return 0;
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
    return 0;
}
