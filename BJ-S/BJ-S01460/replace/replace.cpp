#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200005][2],t[200005][2];
map<pair<string,string>,int> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,l1=0,l2=0;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],l1+=s[i][0].size()+s[i][1].size();
    for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1],l2+=t[i][0].size()+t[i][1].size();
    if(l1<=2000&&l2<=2000){
        for(int i=1;i<=n;i++) mp[make_pair(s[i][0],s[i][1])]++;
        for(int i=1;i<=q;i++){
            if(t[i][0].size()!=t[i][1].size()) {cout<<"0\n";continue;}
            int p1=0,p2=t[i][0].size()-1;
            ll ans=0;
            while(t[i][0][p1]==t[i][1][p1]) p1++;
            while(t[i][0][p2]==t[i][1][p2]) p2--;
            for(int j=0;j<=p1;j++)
                for(int k=p2;k<t[i][0].size();k++){
                    string tmp1="",tmp2="";
                    for(int l=j;l<=k;l++) tmp1+=t[i][0][l],tmp2+=t[i][1][l];
                    ans+=mp[make_pair(tmp1,tmp2)];
                }
            cout<<ans<<'\n';
        }
    }
}
//too hard T_T