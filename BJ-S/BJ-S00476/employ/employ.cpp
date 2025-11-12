#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510];
const long long mod=998244353;
long long jie(int n){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=1LL*(ans%mod)*(i%mod)%mod;
    }
    return ans%mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    bool one=true;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            one=false;
            break;
        }
    }
    if(one==true){
        cout<<jie(n);
        return 0;
    }
    if(m==n&&!one){
        cout<<0;
    }
    return 0;
}
