#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int n,q;
string s[N],t[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.size(),ans=0;
        for(int i=1;i<=n;i++){
            for(int l=0,r=s[i].size()-1;r<len;l++,r++){
                if(s1.substr(l,r-l+1)==s[i]){
                    if(s1.substr(0,l)+t[i]+s1.substr(r+1,len-r-1)==s2){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
