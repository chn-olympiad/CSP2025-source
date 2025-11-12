#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
const int base=31;
const int mod=998244353;
string s[MAXN][2];
int hs[MAXN][2];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        for(int j=0;j<s[i][0].size();j++){
            hs[i][0]=(hs[i][0]*base+s[i][0][j]-'a'+1)%mod;
            hs[i][1]=(hs[i][1]*base+s[i][1][j]-'a'+1)%mod;
        }
    }
    for(int i=1;i<=q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int srt,edd;
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[j]){
                srt=j;
                break;
            }
        }
        for(int j=s1.size()-1;j>=0;j--){
            if(s1[j]!=s2[j]){
                edd=j;
                break;
            }
        }
        string f,g;
        for(int j=srt;j<=edd;j++){
            f=f+s1[j];
            g=g+s2[j];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j+f.size()-1<s[i][0].size();j++){
                string sss=s[i][0].substr(j,f.size());
                string SSS=s[i][1].substr(j,g.size());
//                cout<<sss<<" "<<SSS<<endl;
                if(sss==f&&SSS==g){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
