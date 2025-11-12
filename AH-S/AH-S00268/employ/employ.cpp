#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,a[510],ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        ans*=i;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}
