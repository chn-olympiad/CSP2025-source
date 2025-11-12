#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=998244353;
int n,q;
string s1[210],s2[210],t1,t2,t3;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n<=100&&q<=200){
        for(int i=1;i<=n;i++){
            cin>>s1[i]>>s2[i];
        }
        while(q--){
            cin>>t1>>t2;
            int ans=0;
            for(int i=1;i<=n;i++){
                if(s1[i].size()>t1.size())continue;
                for(int j=0;j<=t1.size()-s1[i].size();j++){
                    if(t1.substr(j,s1[i].size())==s1[i]){
                        t3=t1.substr(0,j)+s2[i]+t1.substr(j+s1[i].size());
                        if(t2==t3)ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(q--)cout<<"0\n";
    return 0;
}
