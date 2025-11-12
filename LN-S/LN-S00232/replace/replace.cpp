#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> re[200020];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>re[i].first>>re[i].second;
    while(q--){
        string s1,s2;
        int ans=0;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++)
            for(int j=1;j<=s2.size();j++)
                for(int k=1;k<=n;k++)
                    if(s1.substr(i,j)==re[k].first&&s2.substr(i,j)==re[k].second&&s1.substr(0,i)==s2.substr(0,i)&&s1.substr(j+i,s1.size()-j-i)==s2.substr(j+i,s2.size()-j-i)) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
