#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans;
string s[2][200010];
string t[2][200010];
int pl_b[4][200010];
int len[4][200010];
namespace BF_B{
    void init(){
        for(int j=0;j<=1;j++){
            for(int i=1;i<=n;i++){
                len[j][i]=s[j][i].size();
                for(int k=0;k<len[j][i];k++){
                    if(s[j][i][k]=='b'){
                        pl_b[j][i]=k;
                        break;
                    }
                }
            }
        }
        for(int j=2;j<=3;j++){
            for(int i=1;i<=q;i++){
                len[j][i]=t[j-2][i].size();
                for(int k=0;k<len[j][i];k++){
                    if(t[j-2][i][k]=='b'){
                        pl_b[j][i]=k;
                        break;
                    }
                }
            }
        }
    }
    void solve(){
        for(int i=1;i<=q;i++){
            ans=0;
            int del=pl_b[2][i]-pl_b[3][i];
            for(int j=1;j<=n;j++){
                if(pl_b[0][j]-pl_b[1][j]==del&&pl_b[2][i]>=pl_b[0][j]&&pl_b[3][i]>=pl_b[1][j]&&len[2][i]>=len[0][j]&&len[3][i]>=len[1][j]&&len[2][i]==len[3][i]){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[0][i]>>s[1][i];
    }
    for(int i=1;i<=q;i++){
        cin>>t[0][i]>>t[1][i];
    }
    BF_B::init();
    BF_B::solve();
    return 0;
}
