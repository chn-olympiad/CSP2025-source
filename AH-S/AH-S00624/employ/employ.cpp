#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}

