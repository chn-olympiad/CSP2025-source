#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string> > keys;
int n,q;
vector<pair<int,int> >diff;

pair<int,int> getdiff(string s1,string s2){
    pair<int,int> res{0,0};
    int i=0;
    for(;s1[i]==s2[i];i++);
    res.first=i;
    int last_diff=i;
    for(;i<s1.size();i++){
        if (s1[i]!=s2[i]) last_diff=i;
    }
    last_diff+=1;
    res.second=last_diff;
    return res;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    string s1,s2;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        keys.push_back(make_pair(s1,s2));
        diff.push_back(getdiff(s1,s2));
    }
    string t1,t2;
    int ans;
    while(q--){
        ans=0;
        cin>>t1>>t2;
        pair<int,int> targetdiff=getdiff(t1,t2);
        for(int i=0;i<n;i++){
            //cout<<keys[i].second<<"("<< targetdiff.first<<","<< targetdiff.second<<")"<<t2.substr(targetdiff.first-diff[i].first,keys[i].second.size())<<endl;
            if((targetdiff.second-targetdiff.first)!=(diff[i].second-diff[i].first)) continue;
            if(targetdiff.first-diff[i].first+keys[i].second.size()>t2.size()) continue;
            if(targetdiff.first-diff[i].first<0) continue;
            //if(t1.substr(targetdiff.first,targetdiff.second-targetdiff.first)!=keys[i].first.substr(diff[i].first,diff[i].second-diff[i].first)) continue;
            if(t1.substr(targetdiff.first-diff[i].first,keys[i].second.size())!=keys[i].first) continue;
            if(t2.substr(targetdiff.first-diff[i].first,keys[i].second.size())!=keys[i].second) continue;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}