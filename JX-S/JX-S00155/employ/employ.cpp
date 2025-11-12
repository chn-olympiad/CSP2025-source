#include<bits/stdc++.h>
using namespace std;
string s;
long long ans=1,c[510];
const int MOD=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=n;i>=1;i--){
        ans*=i;
        ans%=MOD;
    }
    cout<<ans%MOD;
    return 0;
}
