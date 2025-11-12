#include<bits/stdc++.h>
using namespace std;
int a[1005];
int mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int f=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]==0) f=0;
    }
    if (f==0){
        cout<<0<<endl;
        return 0;
    }
    for (int i=0;i<s.size();i++){
        if (s[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    long long ans=1;
    for (int i=2;i<=n;i++){
        ans=1LL*ans*i%mod;
    }
    cout<<ans<<endl;
    return 0;
}