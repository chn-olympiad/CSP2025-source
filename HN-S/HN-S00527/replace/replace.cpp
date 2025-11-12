#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        m[x]=y;
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int ans=0;
        string x="",s="",y=s1,ss="",sss="";
        for(int i=0;i<s1.size();i++){
            s="";
            ss=x;
            sss=y;
            for(int j=i;j<s1.size();j++){
                s+=s1[j];
                sss.erase(sss.begin());
                if(ss+m[s]+sss==s2){
                    cout<<ss<<" "<<s<<" "<<sss<<endl;
                    ans++;
                }
            }
            x+=s1[i];
            y.erase(y.begin());
        }
        cout<<ans;
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
