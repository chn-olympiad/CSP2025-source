#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[510];
namespace BF_A{
    bool fl=0;
    long long init(){
        long long ans=1;
        for(int i=n;i>=1;i--){
            ans*=i;
            ans%=mod;
        }
        return ans;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m==n){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') BF_A::fl=1;
    }
    if(BF_A::fl==0||m==1){
        cout<<BF_A::init();
        return 0;
    }
    return 0;
}
