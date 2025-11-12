#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,m,c[501],ans=0,bn=0;
long long bj[501]={};
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        bj[c[i]]++;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            bn++;
            if(bn==m){
                bn=i;
                break;
            }
        }
    }
    for(int i=n-1;i>=bn;i--){
        if(s[i]=='1'){
            for(int j=i-m+2;j<=n;j++){
                ans+=bj[j];
                ans%=mod;
            }
        }
    }
    cout<<ans*ans%mod;
    return 0;
}
