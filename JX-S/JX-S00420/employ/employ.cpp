#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,m,a[502],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m){
        for(int i=0;i<s.size();i++){
            if(s[i]==0){
                cout<<0;
                return 0;
            }
        }
    }
    ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    cout<<ans%mod;
    return 0;
}
//wu yu le
//C  C  F  N  B
//wo chu ji mi le , ni men xian mu ba (^3^)
//zuo wan yi ba shuang da jin