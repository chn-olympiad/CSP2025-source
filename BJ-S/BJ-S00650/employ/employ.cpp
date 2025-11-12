#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,m;
string s;
int c[505];
long long ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;

    for(int i=1;i<=n;i++) cin>>c[i];
    bool flag=1;
    for(int i=0;i<n;i++){
        if(s[i]!='1'){
            flag=0;
            break;
        }
    }
    if(flag==1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=n-i+1;
            ans=ans%Mod;
        }
        cout<<ans;
    }
    return 0;
}
