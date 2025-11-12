#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][4],t[4];
map<string,bool> m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        m[s[i][1]]=1;
    }while(q--){
        int ans=0;
        cin>>t[1]>>t[2];
        if(m[t[1]]){
            for(int j=1;j<=n;j++){
                if(s[j][1]==t[1]&&s[j][2]==t[2]) ans++;
            }
        }cout<<ans<<"\n";
    }return 0;
}