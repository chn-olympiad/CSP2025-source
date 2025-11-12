#include <bits/stdc++.h>
using namespace std;
const int M = 2e4+5;
int n,m,k;
string mp[M][2];
void solve(){
    int n,q,ans = 0;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>mp[i][0]>>mp[i][1];
    }
    for(int i = 1;i<=q;i++){
        ans = 0;
        string s1,s2;
        cin>>s1>>s2;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<s1.length()-mp[i][0].length()+1;j++){
                if(s1.substr(j,mp[i][0].length()) == mp[i][0]){
                    string x = s1.substr(0,j);
                    string z = s1.substr(j+mp[i][0].length(),s1.length()-j-mp[i][0].length());
                    string nw = "";
                    nw+=x;
                    nw+=mp[i][1];
                    nw+=z;
                    //cout<<nw<<endl;
                    if(nw==s2){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T = 1;
    //cin>>T;
    while(T--)solve();
    fclose(stdin);
    //fclose(stdout);
    return 0;
}
