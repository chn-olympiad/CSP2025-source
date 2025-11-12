#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[300],s2[300];
string cut(string s,int b,int e){
    if(b>e)return "";
    string ss="";
    for(int i=b;i<=e;i++)ss+=s[i];
    return ss;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int a=1;a<=q;a++){
        string sb,se,s3;
        cin>>sb>>se;
        int ans=0;
        for(int i=0;i<sb.size();i++){
            for(int j=1;j<=n;j++){
                if(i+s1[j].size()>sb.size())continue;
                string s4=cut(sb,0,i-1)+s2[j]+cut(sb,i+s2[j].size(),sb.size()-1);
                if(s4==se)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
