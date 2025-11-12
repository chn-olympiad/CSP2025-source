#include<bits/stdc++.h>
using namespace std;
int n,m,a[600];
string s;
long long ans,mod=998244353,sum;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool o=true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')o=false;
    }
    if(o){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i%mod;
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        if(!o){
            cout<<0;
            return 0;
        }else{
            for(int i=1;i<=n;i++){
                ans=ans*i%mod;
            }
            cout<<ans;
            return 0;
         }
    }
    return 0;
}
