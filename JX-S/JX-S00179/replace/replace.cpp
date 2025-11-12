#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,cnt,ans,l,r;
int a[200020];
string s,st,s1,s2,sr;
map<pair<string,string>,int>mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        mp[{s1,s2}]++;
    }
    while(m--){
        cin>>s1>>s2;
        l=1e9,r=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        s="",st="";
        for(int i=l;i<=r;i++){
            s+=s1[i];
            st+=s2[i];
        }
        ans=0;
        ans+=mp[{s,st}];
        for(int i=l-1;i>=0;i--){
            s=s1[i]+s;
            st=s1[i]+st;
            sr="";
            ans+=mp[{s,st}];
            for(int j=r+1;j<s1.size();j++){
                sr+=s1[j];
                ans+=mp[{s+sr,st+sr}];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
