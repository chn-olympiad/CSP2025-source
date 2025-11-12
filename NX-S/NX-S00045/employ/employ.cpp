#include<bits/stdc++.h>
using namespace std;
int n,m,b[501],mod=998244353,ans=1,xy,nn;
string s;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for (int i=1;i<=n;i++) cin>>b[i];
    if (m==1){
        for (int i=0;i<n;i++){
            if (s[i]=='1') xy=i;
        }
        sort(b+1,b+1+n);
        nn=n;
        for (int i=1;i<n;i++){
            if (s[i]<=i) nn--;
        }
        for (int i=1;i<=nn;i++) ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    for (int i=1;i<=n;i++) ans=ans*i%mod;
    cout<<ans;
    return 0;
}
