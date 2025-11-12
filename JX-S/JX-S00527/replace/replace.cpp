#include<bits/stdc++.h>
using namespace std;
const int N=2e5+25;
const int mod=1e9+7;
string s1[N],s2[N];
string t1[N],t2[N];
vector<int>v;
int n,q,nxt[N];
inline void Kmp(string s1,string s2){
    v.erase(v.begin(),v.end());
    int n=s1.size(),m=s2.size();
    s1=" "+s1;s2=" "+s2;
    int j=0;
    for(int i=2;i<=n;i++){
        while(j&&s1[j+1]!=s1[i])j=nxt[j];
        if(s1[j+1]==s1[i])++j;
        nxt[i]=j;
    }
    j=0;
    for(int i=1;i<=m;i++){
        while(j&&s1[j+1]!=s2[i])j=nxt[j];
        if(s1[j+1]==s2[i])++j;
        if(j==n)v.push_back(i-n+1);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++)
        cin>>t1[i]>>t2[i];
    for(int i=1;i<=q;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            Kmp(s1[j],t1[i]);
            //if(v.size())cout<<s1[j]<<'\n';
            string str=t1[i];
            for(int k=0;k<v.size();k++){
                for(int p=0;p<s1[j].size();p++)
                    str[p+v[k]-1]=s2[j][p];
                if(str==t2[i])++ans;
                for(int p=0;p<s1[j].size();p++)
                    str[p+v[k]-1]=t1[i][p];
            }

        }
        cout<<ans<<'\n';
    }
}
