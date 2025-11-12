#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,tot=0;
map<pair<string,string>,int> mp;
vector<pair<string,string>> v[200005];
string s1,s2;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int l=0,r=s1.size()-1;
        while(l<=r&&s1[l]==s2[l])l++;
        while(l<=r&&s1[r]==s2[r])r--;
        pair<string,string> tmp=make_pair(s1.substr(l,r-l+1),s2.substr(l,r-l+1));
        if(!mp[tmp])mp[tmp]=++tot;
        if(l<=r)v[mp[tmp]].push_back(make_pair(s1.substr(0,l),s1.substr(r+1,s1.size()-r)));
        else v[mp[tmp]].push_back(make_pair("",""));
    }
    while(q--){
        cin>>s1>>s2;
        if(s1.size()!=s2.size())cout<<0<<"\n";
        else{
            int l=0,r=s1.size()-1;
            while(l<=r&&s1[l]==s2[l])l++;
            while(l<=r&&s1[r]==s2[r])r--;
            int tmp=mp[make_pair(s1.substr(l,r-l+1),s2.substr(l,r-l+1))],ans=0;
            for(int i=0;i<v[tmp].size();i++){
                int x=v[tmp][i].first.size(),y=v[tmp][i].second.size();
                if(x<=l&&v[tmp][i].first==s1.substr(l-x,x)&&r+y<=s1.size()-1&&v[tmp][i].second==s1.substr(r+1,y))ans++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
