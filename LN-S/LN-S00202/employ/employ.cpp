#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    cout<<ans;
return 0;
}
