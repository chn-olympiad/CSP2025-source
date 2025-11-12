#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    ll ans=1;
    for(int i=1;i<=n;i++)
        ans*=i;
    cout<<ans;
return 0;
}
