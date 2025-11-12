#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2214],t[2214];
bool cmp(int pos,string t,string s){
    for(int i=0;i<s.size()&&pos+i<t.size();i++){
        if(t[pos+i]!=s[i]) return 0;
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
    while(q--)
    {
        int ans=0;
        string s1,s2;cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<0<<'\n';
            continue;
        }
        int m=s1.size(),l,r;s1=' '+s1,s2=' '+s2;
        for(int i=1;i<=m;i++){
            if(s1[i]!=s2[i]){
                l=i;break;
            }
        }
        for(int i=m;i>=1;i--){
            if(s1[i]!=s2[i]){
                r=i;
                break;
            }
        }
        for(int i=1;i<=l;i++)
            for(int j=1;j<=n;j++){
            if(s[j].size()<r-i+1) continue;
            ans+=(cmp(i,s1,s[j])&&cmp(i,s2,t[j]));// cout<<i<<' '<<j<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
