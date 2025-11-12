#include<bits/stdc++.h>
using namespace std;
int n,q,rans;
pair<string,string>s[200010];
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0),cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
    for(string t1,t2;q--;){
        cin>>t1>>t2,rans=0;
        for(int i=0;i<t1.size();i++)for(int j=1;j<=n;j++)if(i+s[j].first.size()<=t1.size()&&t1.substr(i,s[j].first.size())==s[j].first&&t1.substr(0,i)+s[j].second+t1.substr(i+s[j].second.size())==t2)rans++;
        cout<<rans<<'\n';
    }
}