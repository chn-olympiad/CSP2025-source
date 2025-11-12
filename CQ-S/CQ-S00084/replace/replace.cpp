//Luogu: 1116515 Could you subscribe me?
#include <bits/stdc++.h>
using namespace std;
/*
那是我，最后的温柔也是我爱你的原因。
*/
int n,q;
string s[200005][2],t[2];
typedef pair<string,string> pss;
set<pair<pss,pss>> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        int len=s[i][0].size(),l=-1,r=-1;
        for(int j=0;j<len;j++){
            if(s[i][0][j]!=s[i][1][j]){
                if(l==-1) l=j;
                r=j;
            }
        }
        if(l!=-1){
            pss t={s[i][0].substr(l,r-l+1),s[i][1].substr(l,r-l+1)};
            string o1=s[i][0].substr(0,l),o2=s[i][0].substr(r+1);
            reverse(o1.begin(),o1.end());
            mp.insert({t,{o1,o2}});
        }
    }
    while(q--){
        cin>>t[0]>>t[1];
        int len=t[0].size(),l=-1,r=-1;
        for(int j=0;j<len;j++){
            if(t[0][j]!=t[1][j]){
                if(l==-1) l=j;
                r=j;
            }
        }
        pss res={t[0].substr(l,r-l+1),t[1].substr(l,r-l+1)};
        string p="",q="";
        int ans=0;
        for(int i=l;i>=0;i--){
            q="";
            for(int j=r;j<=len;j++){
                if(mp.find({res,{p,q}})!=mp.end()) ans++;
                if(j!=len) q+=t[0][j+1];
            }
            if(i!=len) p+=t[0][i-1];
        }
        printf("%d\n",ans);
    }
    return 0;
}